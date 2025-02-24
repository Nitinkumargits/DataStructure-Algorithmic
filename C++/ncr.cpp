#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int ncr(int n, int r)
{
    int num = fact(n);
    int deno = fact(r) * fact(n - r);
    return (num / deno);
}

int RecNCR(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    return RecNCR(n - 1, r - 1) + RecNCR(n - 1, r);
}
int main()
{
    cout << ncr(5, 2) << endl;
    cout << RecNCR(5, 2) << endl;
    cout << ncr(2, 2);
}