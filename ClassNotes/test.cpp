#include <iostream> 
#include <cstdlib>

using namespace std;

double divide (double x, int times) {
    if (times == 0) {
        return 0; 
    }
    else {
        return (x) /((x) + divide(x, times - 1));
    }
    
}

int main()
{
    for (int i = 1; i < 10; i++) {
        cout << divide(i, 3) << endl;
    }

    return 0;
}