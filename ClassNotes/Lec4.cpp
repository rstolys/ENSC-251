//Notes from lecture 4

/*
    A data structure with multiple pointers in is is called a tree 
        When the structure has just two pointers it refers to a binary tree

    Unions:
        This is a type of data type which reserves space for multiple variables but only will accecpt 1 type 
        When creating the program, if you dont know what varaible you need to use can define a union for multiple 
        types. Later when you know you can simply define the idetifier as a type you would like
    One a union type is defined to be a specific type, you cannot input a different data item into it 
        this will cause a corruption of the data
    Only the last data item enetered will be valid 

    Unions can be useful in strutures to hold many types of varaibles as a single element
        can also be useful to include a tag with the union to indicate which data type the element is


    Templates are another type of dynamic variable which has the abilty to be any type depending on the
        resolution made farther downt the program  

*/

#include <iostream>

using namespace std;

union special {
    int number; 
    float big_number;
    double bigger_number;
    char letter; 
};

template < class T >      //Always needed, defines unkown type T
class unknown {
    public:
    T name; 
    T number;

    void print()
    {
        cout << name << endl;
        cout << number << endl;
    }
};

int main()
{

    //This is not working, but declaration is correct 
    //using a union 
    special num = {10};      //when using a union must initialzie with curly braces
    special letter = {'r'};     //Must also use name that is assigned in the union structure
    //These are two seperate variables

    //using templates 
    unknown <int> test; 
    test.name = 5; 
    test.number = 10; 

    //cout << special.number << endl;

    test.print();



    return 0;
}