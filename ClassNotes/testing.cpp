#include <iostream>

using namespace std;



int* staticfun () {
    static int a = 10; 
    cout << &a << endl;
    return &a; 
}

int main() 
{
    // int * astat; 
    // astat = staticfun(); 

    // cout << astat << endl;

    cout << (1/3.0) << endl;

    return 0; 
}