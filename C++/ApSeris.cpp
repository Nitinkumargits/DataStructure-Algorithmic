#include <iostream>
using namespace std;
int printAP(int a, int d, int n)
{
    int curr_item = a;
    for (int i = 0; i < n; i++)
    {
        cout << curr_item << " ";
        curr_item = curr_item * d;
    }
}
int main()
{
    int x = 2;
    int y = 4;
    int z = 10;
    printAP(x, y, z);
    return 0;
}