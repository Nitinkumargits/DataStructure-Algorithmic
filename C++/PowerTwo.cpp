#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    long long power = n; // Convert n to long long to handle INT_MIN
    if (power < 0)
    {
        x = 1 / x;
        power = -power; // Convert n to positive
    }

    // Base case
    if (power == 0)
        return 1;

    // Recursively compute power

    double half = myPow(x, power / 2);
    if (power % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int main()
{
    cout << myPow(2.00000, 10) << endl;          // Output: 1024.00000
    cout << myPow(2.00000, -2) << endl;          // Output: 0.25000
    cout << myPow(2.10000, 3) << endl;           // Output: 9.26100
    cout << myPow(2.00000, -2147483648) << endl; // Handles INT_MIN safely
    return 0;
}
