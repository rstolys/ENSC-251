//Notes from lecture 1

//Getline allows you to get input for a string 
//

#include <iostream>
#include <string>       //allows you to use c++ string library

using namespace std;

int main()
{
    string x;

    cout << "Input a string: " << endl;

    //getline(source, location);
    getline(cin,x);         //This means the input from cin will be put into the varaible x

    cout << endl << "Your string input is: " << endl <<  x << endl;


    return 0;
}