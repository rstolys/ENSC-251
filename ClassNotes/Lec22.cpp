//Notes from lecture 22
/*
    object orientation 
        discussion of function pointers
    int (*)(int, int) --> the (*) syntax is a pointer to a function 

*/

#include <iostream>

using namespace std; 

struct ship {
    int crew_count; 
    string captain; 
    
    void (*hello)(ship*);       //Function pointer in struct
};

void pirate_hello(ship* thisp) {
    cout << "ARRR" << endl;
    cout << "Captain is: " << thisp->captain << endl;
}

void cargo_hello(ship* thisp) {
    cout << "AHOY!" << endl;
    cout << "Captain is: " << thisp->captain << endl;
}

ship* make_pirate(string name) {
    ship* temp = new ship; 
    temp->captain = name;
    temp->hello = pirate_hello;
    return temp;
}

ship* make_cargo(string name) {
    ship* temp = new ship; 
    temp->captain = name;
    temp->hello = cargo_hello;
    return temp;
}



int add (int a, int b) {
    return a + b; 
}

//example of function pointer as input to function

int apply(int fun(int, int), int first, int second) {         //trying to apply any function to inputs
    return fun(first, second);
}

int main(int argc, char** argv)  
{
    //cout << argv[1] << endl;            // printing second input to program

    //fun(int, int) = add;    does NOT work 
    //auto fun = add;           This does work

    int (*fun2)(int, int) = add;       //This is a function pointer call fun2, to the function add


    cout << add(5,6) << endl;
    //cout << fun(5,6) << endl;
    cout << fun2(5,6) << endl;
    cout << apply(add, 5, 6) << endl;

    ship* the_fancy = make_pirate("Henry Avery"); 
    ship* titanic = make_cargo("Edward John Smith");
    titanic->hello(titanic);
    the_fancy->hello(the_fancy);
    

    return 0; 
}