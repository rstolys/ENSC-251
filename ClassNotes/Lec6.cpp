//Notes from lecture 6 

/*
    Talked about inheritance 
        This is when a class has new information in addtion to all the class info which comes from another class

*/

#include <iostream>
#include <string>
#include "Lec5.cpp"     //This will copy infomration from Lec 6 cpp file into this file 

using namespace std; 


class new_ship : public ship {         //This will inherit all the data from ship and have the new information in new_ship
    public: 
    int passengers;

    new_ship(int ID, string name, string type, int persons) : ship(ID, name, type, persons)
    {
        passengers = persons;

    }

    ~new_ship()
    {
        cout << endl << "There were " << passengers << " passengers on board" << endl;
    }
};

int main()  
{
    new_ship* my_ship = new new_ship(20000, "Ryan", "Unknown", 0);
    my_ship->ID = 12345;
    my_ship->name = "Ryan";
    my_ship->type = "Battle";
    my_ship->passengers = 55; 

    delete my_ship; 

    return 0; 
}