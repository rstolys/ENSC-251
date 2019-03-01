//Notes from lecture 20 
/*
Agenda  -- covering c++ reference pointers 
        -- analysis 
    
Final project is due by Dec 4th 
search: machine learning datasets -- good for testing 
    gisette is data set we will be tested on 
    https://archive.ics.uci.edu/ml/machine-learning-databases/gisette/

Reference pointers must point to variable while a pointer varibale can be set to NULL. 


Encode app to practice other langauges 
*/

#include <iostream> 
#include <vector>

using namespace std;

int good_function(int a) {          //doesnt edit the memory it recieves, will always give same answer back 
    int b = a + 1; 
    return b; 
}

int still_good_function(int a) {           
    a = a + 1; 
    return a; 
}

void evil_function(int* a) {           
    a = a + 1;                //This will change the memory of the located in the pointer to a 
}   

int sneaky_function(int& a) {   //This is also taking address of the input        
     a = a + 1;     //Don't need to dereference pointer        //Writing to location in memory that has that value passed
    return a;                   //When calling, it is not clear the value is being passed by refernce 
}

static int counter() {          //static is used when building across multiple files, will not allow this to be viewed outside of file 
    static int count = 0;       //static means it acts as a global variable to one function --- //this will only run once
    count = count + 1;          //once it is initialized once it doesnt not get initialized after 
    return count;
}

class demo {
public:
    int test; 

    int operator+(int a) {          //allows definition of the operator acting on class 
        test = test + a;            
        return test; 
    }

    float operator+(float a) {          //operator must be prexisting operator in c++
        test = (float)test + a;
        return test; 
    }
};

int main (int argc, char** argv) {          //Main must take two inputs, int argc and char** argv 
    //cout << argc << endl;           //acts as argument counter
    // int current_arg = 0; 
    // while (current_arg != argc) {
    //     cout << argv[current_arg] << endl;      //This is how you will read the file in for the final project 
    //     current_arg++;                           //for final project, argv[1] will be file we want to open 
    // }

    // demo* dem = new demo; 
    // dem->test = 0; 
    // cout << dem->test << endl;

    // demo d2;            ///dont need pointer
    // d2.test = 765; 
    // cout << d2.test << endl;

    // vector<demo> v;
    // demo a; 
    // v.push_back(a); 
    // v[0].test = 123; 
    // cout << v[0].test << endl; 


    //operator overloading 
    //have a single operator meaning the same thing 
    // << is shift operator 
    cout << "blah" << endl;     // moves blah to cout 

    demo d; 
    d.test = 654; 
    int temp = d + 123;           //This + is an operator of the class demo 
    cout << d.test << endl;       //prints 777


    return 0; 
}