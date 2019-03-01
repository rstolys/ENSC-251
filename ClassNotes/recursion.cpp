#include <iostream> 

using namespace std; 

void printB(int num);

int main () {

    int number; 

    cin >> number; 

    printB(number);

    cout << endl;

    return 0;
}


void printB(int num) {

    if (num < 1) {
        return;
    }
    cout << num % 10; 

    printB(num/10); 

    return;
}