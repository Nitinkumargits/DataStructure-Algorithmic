#include <iostream>
#include <vector>
#include <limits.h> // Include for INT_MAX

using namespace std;

int secondLargest(vector<int> &a, int n)
{
    int largest = a[0];
    int slargest = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > slargest)
        {
            slargest = a[i];
        }
    }

    return slargest;
}

int secondSmallest(vector<int> &a, int n)
{
    int smallest = a[0];
    int ssmallest = INT_MAX; // Corrected from INT64_MAX to INT_MAX

    for (int i = 0; i < n; i++)
    {
        if (a[i] < smallest)
        {
            ssmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] != smallest && a[i] < ssmallest)
        {
            ssmallest = a[i];
        }
    }
    return ssmallest;
}

vector<int> secondOrderElement(int n, vector<int> &a)
{
    int slargest = secondLargest(a, n);
    int ssmallest = secondSmallest(a, n);

    return {slargest, ssmallest};
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5}; // Using vector instead of raw array
    int n = arr.size();

    vector<int> result = secondOrderElement(n, arr); // Calling function correctly

    // Print output in array format
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
