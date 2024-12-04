#include <iostream>
#include <vector>
using namespace std;

// Recursive function to separate the digits of a positive integer
// and add them to a given vector
void split_number(int num, vector<int> &result)
{
    if (num > 0)
    {
        split_number(num / 10, result);
        result.push_back(num % 10);
    }
}

// Function to add two arrays
void add(vector<int> const &a, vector<int> const &b, vector<int> &result)
{
    int m = a.size(), n = b.size();

    // loop till either `a` or `b` runs out
    int i = 0;
    while (i < m && i < n)
    {
        // get the sum of the next element from each array
        int sum = a[i] + b[i];

        // separate the digits of the sum and add them to the output vector
        split_number(sum, result);

        i++;
    }

    // process remaining elements of the first vector, if any
    while (i < m)
    {
        split_number(a[i++], result);
    }

    // process remaining elements of the second vector, if any
    while (i < n)
    {
        split_number(b[i++], result);
    }
}

int main()
{
    // input vectors
    vector<int> a = {23, 5, 2, 7, 87};
    vector<int> b = {4, 67, 2, 8};

    // vector to store the output
    vector<int> result;
    add(a, b, result);

    // print the output vector
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}