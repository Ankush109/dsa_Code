#include <iostream>
using namespace std;
// this is how to swap two numbers without using a third variable:-
// important:-
int main()
{
    int a = 5;
    int b = 7;
    a = a ^ b; // a = 5 ^ 7
    b = a ^ b; // b = 5 ^ 7 ^ 7 = 5
    a = a ^ b; // a = 5 ^ 7 ^ 5 = 7
    cout << a << " " << b << endl;
    return 0;
}