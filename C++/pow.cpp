
#include <iostream>

using namespace std;

double myPow(double x, int n)
{
    // Handle edge case where n is the minimum integer value
    long long power = n;
    if (power < 0)
    {
        x = 1 / x;
        power = -power;
    }

    double result = 1.0;
    while (power > 0)
    {
        if (power % 2 == 1)
        { // If n is odd, multiply result by x
            result *= x;
        }
        x *= x;     // Square the base
        power /= 2; // Divide exponent by 2
    }

    return result;
}

int main()
{
    cout << myPow(2.00000, 10) << endl; // Output: 1024.00000
    cout << myPow(2.10000, 3) << endl;  // Output: 9.26100
    cout << myPow(2.00000, -2) << endl; // Output: 0.25000
    return 0;
}
