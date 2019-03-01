//Notes from lec 14 

/*
    Review: will cover all material to this point

    in cout << , can perform arithmitic in statement -- cout << 5+6 << endl;



*/

#include <iostream>
#include <memory>       //includes shared pointers 

using namespace std; 

class compund_c {
//public:             //allows you to access the class data
private: 
    int first;
    int second;
       
public:                    //Can have methods in classes and structures which is a local function 
    int add(){
        return first + second;          //Will add the elements of the class
    }

    compund_c(int first, int second)        //This is called a construtor and will run whenever a class of this type is created
    {
        //Can have conditions
        if (first < 0 || second < 0) {
            throw -1;               //means the class will 'crash' until the error is caught
        }
        this->first = first;                //The this-> indicates you are referring to the varible names first 
        this->second = second;                  //that is part of the class not the function; 
    }

private:            //Only the class can access the data under the private header
    int third;
};

struct compund_s {
    int first;
    int second;
};

union compound_u {
    int first;
    int second;
};

int main()
{
    //The above compund variables defines a data type
    compund_s* my_s = new compund_s;        //Needs to be initalized to a location
    my_s->first = 10; 
    cout << my_s->first << endl;


    delete my_s;        //This will release the allocated memory back to the heap
                        //The my_s is still a pointer that exists but the memory it points to is no longer allocated to it 

    //When there is a chance to have a throw error 
    compund_c* my_c;        //Doing this outside the try block will allow you to access the pointer outside the try block
    try{
        my_c = new compund_c(1,2); 
    }
    catch(...){         //can have catch(int number) -- this will allow you to use the thrown item 
        cout << "The class failed to create due to a negative initalization" << endl;
    }
        //The catch statement (...) can specify whatever conditions you want to catch 
            //This will result in different responses to specific errors
            //Catch will only execute when there is an error in the try block 
            //you will have multiple catch statements for each try block 


    delete my_c; 

    compound_u* my_u = new compound_u; 
    my_u->first = 432; 
    my_u->second = 987; 
        //The 987 will over write the 432 in a union

    delete my_u; 



    return 0;
}




class demo { 
public:
    int a; 
    demo(int initial){
        a = initial;
    }

    ~demo(){
        cout << "this pointer is being deleted" << endl;
    }
};

template <class my_data_type>       //This will define an unknown data type that will be resolved at a later time 
    //can code with this type in the program but once you try to use it you have to choose the data type

int sub_main()          //working on different material
{
    int* array = new int[10];       //creates a pointer to an array of 10 elements 

    //array[-1];  This is located outside the block of allocated memory 
    //array[10]; thiis ia also outside the array 
        //indexes are 0-> size -1; 

    //shared_ptr<demo> shared = make_shared<demo>(20);      --The memort function is not in saved libraries 
        //This will create a new pointer called shared that points to a memory block which may have multiple pointers to it 
        //Once there are no references to the data the program will delete it for you


    delete [] array; 

    return 0; 
}

#include <string>
using namespace std;

//Talking about inheritence 
class student1 {
public: 
    string name; 
    void work() {
        cout << "I am working" << endl;
    }
};

class grad_student : public student1 {      //need to define student as public to access the information
public:
    string project; 
    void smart(){
        cout << "I am smart" << endl;
    }
};

int sub_main2 ()
{

    grad_student* not_me = new grad_student; 
    not_me->work(); 
    not_me->smart(); 


    delete not_me;

    return 0;
}


//Data structures
/*
Array is a squence of elements that are in line and of the same type, indexes provide limits of array 

Linked list have a head and tail where the head is the data and the tail is the pointer to the next element 
    inserting element in middle is much simpler than in array 
    searching linked lists are very slow since you have to traverse the list 

Heap has 3 chunks where there is a element and two pointers (left and right child) 
    this can be represented as an array 
    heap property is that all elements below the parent are less than the parent 
        can also be greater depending on conditions set 
    only the top of the heap can be removed easily 

Binary Tree 
    items to left are smaller while items are the right are larger than the parent node 
        this continues the entire way down the tree

*/



