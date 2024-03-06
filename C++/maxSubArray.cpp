#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 1; i <= 5; i++)
    {
        v.push_back(i);
    }
    int max1 = INT32_MIN, sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        max1 = max(max1, sum);
        if (sum < 0)
        {
            sum = 0;
        }
        cout << max1;
        return 0;
    }
}