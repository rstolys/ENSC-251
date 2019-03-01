#include <iostream> 
#include <omp.h>       //allows you to run programs that use multiple cores/ processors in computer

using namespace std; 



int main()
{

const int count = 10000;
int array[count]; 

int sum = 0;
int current_item = 0;

#pragma omp parallel
{
    while (current_item != count)
    {
    sum = sum + array[count];
    current_item++; 
    } 
    //1
    //This isnt very fast, can use optimizations of g++ complier 
}
//This allows you to run the computations on multiple processors
    //Cannot use while loops in with open mp 

#pragma omp parallel
{
    cout << "HI!" << endl; 
}
//This will print Hi for the number of processors you have 

/* these two examples show how omp can be dangerous */ 

//Here is how you can properly use it 
    //FOR LOOP 

#pragma omp parallel for        //This is used when doing in for loop 
    for (int i = 0; i < count; i++)     //Cant usually have != in for loop 
    {
        array[i] = i; 
    }

#pragma omp parallel for reduction(+:sum)      
 for (int i = 0; i < count; i++)     //Cant usually have != in for loop 
    {
       sum = sum + array[i];
    }
 //The additon of reduction will allow you to do sum across multiple processors  
   


/************************************/



    return 0; 
}


/* NOTES 
1. Using g++ compiler -00 g++ name will not use any optimizations 
    if you do -01 g++ name will optimize, -02 g++ name is a second optimization. 
    will make program run faster, each number does more optimizations
        higher numbers dont optimize too much, -0fast is the best optimization 
    Can test using time ./a.out command in terminal 
when using time ./a.out will return 3 values 
    real -- from the time the input in entered on the screen to finish 
    user -- time program too to run -- what you can control ***
    sys -- time for system to start program 

When you optimize the program becomes independent and changes program to get same result 
    compliing with g++ -g -0g name will allow you to debug your program and optimize without interfering with debugging 
    can also use -Wall and -Wextra that will give you all the possible error messages 

2.  Optimizing code using <omp.h> "openMP" 
    include header 
    #pragma omp parallel 
    include -fopenmp in complier command line 
        This can be dangerous 
        user time is the sum of the times at each processor 
    While loops with openmp do not go well together 

This is a great tool is you learn how to properly use it 
Cant use this when summing things since the sum of the next step depends on the sum of the previous step
    Will likely give wrong result unless you account for it 

Things to know for using omp.h 
    #pragma omp parallel
        will use multiple processors 
    reduction(+:sum) 
        allows you to do computations which depend on each other with multiple processors 
            such as summing numbers to itself 


3. Compiling with multiple files 
    if you reference a function that is not declared, the program will not know how to handle it
    If that function is located in a second file
        can include file by using #include "filename.cpp"
            This will copy and paste it into the original file being compiled 
        Every file needs at leats a prototype of the functions being used ***
    You can compile both files at the same time and the function which exists in on that also exists in 
        the other will work on fucntion call of original functions 
    ***Instead of inclduing the prototypes, you can #include a header file that contains all of the prototypes 
        This means if you have a function that had all the definitions and another with the prototypes, 
        You can share the header file to allow other users to use those same functions without typing their prototypes 

4. Header Files -- Can have file type .hpp for c++ 
    for accessing files use quote marks if the file is saved to your disk 

5. Using vectors 
    need #include <vector> 

    vector <int> int_storgae; 
        This will create a new vector 
        you can access elements and use member functions of the vector class to do certain things to the vector

    int_storage.push_back(5);   --Will place 5 into vector 
    cout << int_storage.at(0) << endl;  --access element in position 0 
        -- Using the push back fucntion will place element in the last position of vector (first unfilled)
        --vectors are basically arrays which change size each time you add an element 
        -- All of the vector fucntions can be looked up on cppreference 



*/

