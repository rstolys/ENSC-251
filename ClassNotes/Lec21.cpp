//Notes from lecture 21
/*
Various programs can tell you your program is wrong
    CBMC (bounded model checking) is an example 
    Will run through sizes of data (n values) to find if error occurs

    To test program: 
        zzuf -r 0.5 -i ./a.out          command line input 
    Give it an input and it will test ./a.out

*/

#include <iostream> 
#include <vector>
#include <string>

using namespace std;

int main (int argc, char** argv) {          //Main must take two inputs, int argc and char** argv

    string dummy;

    cin >> dummy;
    cin >> dummy; 

    int vars; 
    int clauses;
    
    cin >> vars;
    cin >> clauses;     //If these are negative it will result in error in allocation of array

    int** clause_array = new int*[clauses]; 

    int current = 0;
    while (current != clauses) {
        clause_array[current] = new int[vars]; 
    }

    cout << "Allocated: " << vars << " " << clauses << endl;

    return 0; 
}