#include <iostream>
using namespace std;

int F[10];

int mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        F[i] = -1;
    }

    cout << mfib(5);
    return 0;
}