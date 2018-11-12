//SAT Solving Done Simply 
//
//By: Ryan Stolys 
//Last Edit Nov. 3rd, 2018

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>


using namespace std; 

class SATisfiability {
public: 
    bool* propose; 
    int nbvar; 

    SATisfiability (int nbvar) {
        propose = new bool[nbvar + 1];      //This will define an array where each element refers to the varaible
        this->nbvar = nbvar;                //and is either true or false
    }                                       

   
    void guess(int seed) {
        propose[0] = true;          //The variable 0 is never checked, will be set to default value of true
        srand(seed); 
         for (int i = 1; i <= nbvar; i++) {
            if ((rand() % 2) == 1) {
                propose[i] = true; 
            }
            else {
                propose[i] = false;
            }
        }
    }

    bool check (string clause) {        
        bool check = false;
        int test;
        istringstream temp(clause); 
        //temp << clause;
        if (!temp) {                //******* Has not been tested
            cin.clear(); 
            return false;
        }
        for (int i = 0; i < clause.size(); i++) {
            temp >> test;
            if (test == abs(test)) {                //element is positive 
                if (propose[test] == true) { 
                    check = true; 
                    break;                          //once one soltuion is correct, clause is satisfied
                }
                else {
                    check = false;                  //Try next element in loop
                }
            }
            else {
                if (propose[abs(test)] == false) { 
                    check = true; 
                    break;                      //once one soltuion is correct, clause is satisfied
                }
                else {
                    check = false;              //Try next element in loop
                }
            } 
        }
        return check;
    }


    void print_soln () {
        cout << "A solution to this SAT problem is: " << endl;
        cout << "V  ";
        for (int i = 1; i <= nbvar; i++) {
            if (propose[i] == true) {
                cout << "x" << i << " ";
            }
            else if (propose[i] == false) {
                cout << "-x" << i << " ";
            }
        }
        cout << endl << endl;
    }

    ~SATisfiability(){
        //Deallocate memory
        delete [] propose; 
    }
};

int main()
{
    //Varibles for file
    string file_name;
    ifstream SAT_file;

    //Variables for clause information
    int nbvar; 
    int nbclause;
    int seed = 1;
    bool check = true;
    string line; 
    int number[2];

    //Varibales for checking solution
    int i = 0;
    double count = 0;
    double max = 100000000;       //100 million


    //Request File name: 
    cout << "Enter the file name in the form: name.txt" << endl;
    cin >> file_name;
    cout << endl << endl;
    
    SAT_file.open (file_name);
   
    if(!SAT_file.is_open()) {       //Will execute if file is not correctly opened
        cout << "File failed to open" << endl;
        return -1;
    }

    //Read information nbvar and nbclause

    while (true) {
        getline(SAT_file, line); 
        line.insert (line.end(),1,'-');         //insert null character to allow final charcter to be read
        if (line.front() == 'c') {              //line being read is comment 
            //ignore line
            continue;           //go get next line 
        }
        else {                  //first line after comments contains varibale information
            int tens;
            int ones;
            int count = 0;
            for (int i = 1; i < line.size(); i++) {
                if (isdigit(line.at(i-1)) && isdigit(line.at(i))) {
                    tens = (int)line.at(i-1) - 48;
                    ones =  (int)line.at(i) - 48;
                    number[count] = tens*10 + ones;
                    count++;
                }
                else if (isdigit(line.at(i-1)) && ones != (int)line.at(i-1) - 48) {
                    number[count] = (int)line.at(i-1) - 48;
                    count++;
                }
            }
        }
        break;          //now have information on number of varaibles and number of clauses
    }

    //Assign information to variable names
    nbvar = number[0];
    nbclause = number[1];

    //Define solution class
    SATisfiability* solution = new SATisfiability(nbvar);           //Needed to get information about nbvar


    srand(seed);

    //Create loop to check each clause and determine if it true or not 
    while (i < nbclause) {
        solution->guess(count);             //Make guess
        getline(SAT_file, line);            //Save line into string
        check = solution->check(line);      //Pass string to check method
        i++;
        if (count >= max) {                         //will only enter after 100th million iteration
            cout << "No solution can be found" << endl;
            delete solution;            //Deallocate memory
            return -1;                  //End program
            //This is only here to avoid infinte run times or non-satisfiable cases
        }

        if (check == false) {
            i = 0;                          //reset counter
            count++;                        //increment counter for number of attempts;
            continue;                       //Try again 
        }
    }
    //Loop will exit when all clauses have been checked and are satified 


    //Print solution 
    solution->print_soln();
   

    SAT_file.close();
    delete solution;

    return 0;
}




    //Algorithm
    /*
        Read the file and record all the number of variables and the number of clasues
        Read each clause and record in varibales for each one 
        For each variable type assign a random value of either true or false 
            rand() % 2 where 1 = true and 0 = false; 
                Can think of the ~32 variables in place as a binary number, iterate from 0 -> 1111... 
                This will result in every case being hit, if the  
                    This what he wants 351 to do but we have to simply guess randomly... 
            
            Create a class which has 32 boolean values
                include a method in the class which will assign each of the variables a random value (1 OR 0)
            Iterate a loop where a clause is read and where a number is seen call that class boolean value
                you can AND each element in the clause, When there is a negative value, must not the boolean value
                if it evaluates to true then move to the next clause, if it evaluates to false
                    call reset method in class and start from clause 1 again
            Iterate this method with a counter
                if the counter gets 10 billion then terminate the program saying there was no soltuon 
                    will need to delcare this counter as a doule to manage its size. 
                        **The only purpose of this is to ensure program doesnt run forever. 

    */
