// of two numbers in a range
#include <bits/stdc++.h>
using namespace std;

// method to get maximum xor value in range [L, R]
int maxXORInRange(int L, int R)
{
    // get xor of limits
    int LXR = L ^ R;

    //  loop to get msb position of L^R
    int msbPos = 0;
    while (LXR)
    {
        msbPos++;
        LXR >>= 1;
    }

    // Simply return the required maximum value.
    return (1 << msbPos) - 1; // 2 ^ msbPos - 1
}

//  Driver code to test above methods
int main()
{
    int L = 8;
    int R = 20;
    cout << maxXORInRange(L, R) << endl;
    return 0;
}