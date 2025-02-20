#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    cout << "*p :" << *p << endl;
    cout << "&a :" << &a << endl;
    cout << "p :" << p << endl;
    cout << "p++ :" << ++p << endl;
    cout << "&p :" << &p << endl;
}