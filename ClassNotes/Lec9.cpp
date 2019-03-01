//Notes from lecture 9

/*
    Throw in classes
        When a class revieves a value it cannot work with it can throw 
        A throw basically means the class can't deal with it and so who ever called the class
        has to deal with it 

    If a throw is not caught it will crash the program 
    To catch a throw use a try {} catch(...) {}; 
    If the statements in the try braces fail then the catch brace will handle the issue
        If the statements in the try braces dont fail the catch is ignored. 

    Note that variables declared in the try block are local to that block

    When the catch statements run the program will continue
        catch statements can try to fix the problem so that the prgram will continue to run
    Catch conditions can be anything, since anything can be thrown
        If a string is thrown the catch can be specifc and catch the string 
    Can have multiple catch statements for each try block 
    This is another method of acting in accrodance with error since throw types may differ

    When classes allcoate memory 
        the memory has to be deallocated in the destructor since the deallocation of the 
        class itself will still result in a loss of the memory pointed to by the class

*/

#include <iostream>

using namespace std;

class annoy
{
    public:
    int age; 

    annoy(int age)
    {
        if (age < 0)
        {
            throw (-1); 
        }
        else 
        {
            this->age = age; 
        }
    }

    ~annoy()
    {
        cout << age << endl;
    }

};

int main()
{
    annoy* ryan; 
    try
    {
        ryan = new annoy(-2);
        int x = 5; 
    }
    catch(int type)         //by having a value you can determine what the throw was an this act 
                            //depending on the error
    {
        cout << "caught it" << endl << "Was of type " << type << endl;
    }

    //cout << x << endl;  This wont work since varibale x is not declared in main
   
    delete ryan;
   
    return 0;
}