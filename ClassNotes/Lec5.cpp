//Notes from lecture 6 

/* 
    Objects are stuctures with more control over access to element in them 
        They can have methods, which are functions within the object 

    Constructors are functions with the same name as the class that will run every time the class is created 
        This can force the object to be created with initialized values 

    Destructors are similar to constructors expect run when object is deleted

    Objects can be party public and partly private, mentioned in previous lecture 
        To access private infomration must use public function 
            Some infomration/ data is meant to be unaccessible 
        These set methods are useful when you want to impose limitations on the input to a value 

    Note in C++ that you can have default values for varibales in a classs

*/

#include <iostream> 
#include <string>

using namespace std; 



class ship {
    public: 
    int ID; 
    string name; 
    string type;

    ship(int ID, string name, string type, int persons)     //Constructor
    {
        if (ID >= 10000 && ID <= 99999)   //ensures id is at least 5 digits long 
        {
             this->ID = ID;
        }
        this->name = name;
        this->type = type;

        if (persons > 0)
        {
            num_pirates = persons;      //Will set number of pirates but that will remain private information
        }
    }

    ~ship()     //Destructor 
    {
        cout << "The ship is going DOWN!!!" << endl; 

        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "We lost " << num_pirates << " pirates in the sinking of " << name << " today" << endl;
    }

    private: 
    int num_pirates; 
};

// int main()       //commented so that call from lec 6 will work
// {
//     ship* my_ship = new ship(12345, "Ryan", "Battleship", 5);

//     cout << "This ship is sailing" << endl; 

//     cout << "This ship is under fire" << endl;

//     delete my_ship;

//     return 0; 
// }