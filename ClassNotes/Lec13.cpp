//Notes from Lecture 13 

/*
    When writing functions with strcutures and classes, always define as a pointer so that you still 
        have access outside of function and can pass address and control it 

    Releasing memory:
        This will release the memory the pointer points to but the pointer will remain until the 
        program/ function terminates just as standard int variables do 

    Keeping track of refernces:
        sometimes there are multiple references to memory you can keep track by having a reference count 
        in the struct/ class
        When are you are done using one refernce decrement the reference, check if it zero 
            if it is zero then you can delete it 

    Auto variable type
        determines what type of variable is best suited to fit and places it as variable type 
        this is not reccomended since you cannot control it and dont know what everything is 
    
    Shared pointers:
        using <memory>
            Will keep track of refernces to memory and delete it when there are no more references 

    Timing:
        using <chrono>
            use chrono::system_clock
            system_clock::time_point t1 = system_clock::now();
            system_clock::time_point t2 = system_clock::now();

*/

#include <iostream>
#include <memory>
#include <sys/time.h>

using namespace std; 

class demo{
    public:
    int a; 

    demo(int initial)       //constructor 
    {
        a = initial;
    }

    ~demo()                 //destructor
    {
        cout << "been deleted" << endl;
    }

};

int main()
{
    int num = 43;
    shared_ptr<demo> shared = make_shared<demo>(num);
        //Once there are no more refernces to the the demo body it will autoatically delete the body
        //This is useful when there are multiple refernces to a body and you dont know when you want to delete it 
    cout << shared->a << endl;


    //Measuring time
    timeval* time = new timeval;

    gettimeofday(time, NULL);

    cout << time->tv_usec << endl;
    cout << time->tv_sec << endl;


    return 0;
}