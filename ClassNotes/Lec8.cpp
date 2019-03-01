//Notes from lecture 8

/*
    Can overwrite functions when using inheritence 
        This means if the intial class has a function and the new class also has that function
        The the more specific fucntion will run 
    
    Leads naturally to virtual functions
        A class which wants to force a class inheriting it to have a function can have 
        a virtual function which has a name but an empty body;

    Any class which inherits it must define this function in order to run -- not true
    
    Ragged array:
        An array made from pointers where each row is of a different length 
        this can be achomplished through the allocated step 

    Representing connections between nodes through an array, 
        The element index ij refers to a connection from i -> j 
        This can be done for any number of nodes 
        If connections go two ways can similify this by using a ragged array since you only
            need the top half if ij = ji

    Linked lists are made with a data element and a pointer 
        if you have two pointers per element you will have a binary tree 
            each node branches into two elements 

    To visit all nodes on a tree, always go left if you can't go left, go right 

    Can represent tree using an array where thre index of the element can indicate the location 
    on the tree 
        Parent @ i 
        Child left = 2i +1;
        Child right = 2i +2; 
*/

#include <iostream>
#include <string>

using namespace std; 


class person{
    public:
    string name; 

    void speak()
    {
        cout << "Hello, my name is " << name << endl;
    }

    virtual void partner(){};
};

class teacher: public person{
    public:
    
    void speak()
    {
        cout << "I am a teacher, a more important type of person" << endl; 
        cout << "My name is " << name << endl;
    }

    void partner()
    {
        cout << "I am a teacher and have no friends, just students" << endl;
    }

};

int main()
{

    teacher young; 
    young.name = "DR";

    young.speak();      //This will execute the most recent speak function

    young.partner(); 


    return 0;
}