//Notes from lecture 3

//Linked list 
/*
    A linked list is a type of array where instead of all the elements falling into line in order in memory
    they are instead simply joined by pointers to various locations in memory 
    
    The main advantage to a linked list is the ability to add and remove elements
        more generally the abilty to change the order of the array 
            In a standard array configuration the removal of an element consists of completely 
            re copying the array into a new array of 1 less element
    
    Linkned lists are slow to navigate since you must go through every element before it 
    to reach the element you are interested in.


    Std C libaray is <stdio.h> 
        For allocating memory need <stdlib.h>

    structures and classes -- These are very similar, major different is that you can limit access to 
        information in object while structures are always public 

    When accessing memory in a strcture/ class which is stack allocated use the dot operator
        means to access tail element of link_list:
            name.tail;      This will access the structure/ class called name (of type link_list)
                            and access the tail element of the structure. 
    When structure/ class is dynamically allocated meaning it is a pinter to the structure use the arrow
        operator:
        name->tail;         //Works the exact same way 

    when you create a stucture/ class the name of the structure becomes a data type which you can make variables of
        simialer to variable of type int:
        int x;
        link_list x;

    For dynamically allocated memory use the delete command in c++ and free in c

    Classes and structures can have function in them making them useful. In order to access
        a private element in a class/ stricture you need to use a public in the function 
    Some private data is never accessible since it is only there for the obects use


*/

#include <iostream>
#include <string>

using namespace std; 


class link_list
{
    public:
    int head;           //This is the data of the element, similar to storage position of the array -- can be of any type
    int* tail;          //This is the pointer to the next element in the list. Must be of same type as data

    void set_name(string input)
    {
        if(name == "Ryan")
        {
            this->name = name;         //The this pointer means you are referring to the element name within the class
        }
    }

    void print()
    {
        cout << head << endl;
        cout << name << endl;
    }

    private: 
    string name;
};      //Last element in the array is set to a nullptr. 



int main()
{   
    link_list* element = new link_list;

    element->head = 12; 
    element->tail = nullptr;

    element->set_name("Ryan");

    element->print();

    //Deallocate memory
    delete element; 

    return 0;
}