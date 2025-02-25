#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute (base^exp) % MOD using modular exponentiation
long long powerMod(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int countGoodDigitStrings(long long n)
{
    long long evenCount = (n + 1) / 2; // ceil(n/2)
    long long oddCount = n / 2;        // floor(n/2)

    long long evenWays = powerMod(5, evenCount, MOD);
    long long oddWays = powerMod(4, oddCount, MOD);

    return (evenWays * oddWays) % MOD;
}

int main()
{
    cout << countGoodDigitStrings(1) << endl;  // Output: 5
    cout << countGoodDigitStrings(4) << endl;  // Output: 400
    cout << countGoodDigitStrings(50) << endl; // Output: 564908303
    return 0;
}
