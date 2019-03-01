//Notes from lecture 7 

/*
    2D array, can make it out of pointers where the original array is a list of pointers
        those pointers each point to an array of integers 
    Can expand this idea for multi dimensional arrays 
        Can use [] notation to access elements allocated through pointers 

    Returning memory
        Delete each pointer which was allocated
    Start with most referenced pointers, in this case the second level of the array 
    The delete the initial row


*/

#include <iostream>

using namespace std; 

int main()
{
    int size = 10; 

    int** array = new int*[size];     //allocated array of 10 pointers to pointers of integers

    for (int i = 0; i < size; i++)
    {
        array[i] = new int[size];       //creates pointer to list of 10 integer 
                       //assigns pointer into list of pointers
    }

    //deallocate the array 
    for (int i = 0; i < size; i++)
    {
        delete [] array[i];     //Will deallocate array 
    }
    delete [] array; 

    //delete name       //only deallocates the pointer itself and not all the array 
                        // memory it references 


    return 0; 
}