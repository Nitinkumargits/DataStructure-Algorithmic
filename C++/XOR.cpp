#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> &a)
{
    int unique = 0;
    for (int num : a)
    {
        unique ^= num; // XOR all numbers
    }
    return unique;
}

int main()
{
    vector<int> arr = {4, 3, 2, 4, 1, 3, 2, 5}; // Corrected initialization
    cout << "Unique Element: " << findUnique(arr) << endl;
    return 0;
}
