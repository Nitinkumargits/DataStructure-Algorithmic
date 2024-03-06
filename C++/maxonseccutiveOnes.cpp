// maximum consecutive 1s in an array
// Return count of maximum consecutive 1's in binary array a[0...n-1]

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMaxLength(bool arr[], int n)
{
    int count = 0;        /// initialize the count
    int result_count = 0; // initialize the max

    for (int i = 0; i < n; i++)
    {

        // Reset the count when the zero is found
        if (arr[i] == 0)
        {
            count = 0;
        }
        else
        {
            // if 1 is found ,increment count and update the result if count bcm more
            count++;
            result_count = max(result_count, count);
        }
    }
    return result_count;
}
int main()
{
    bool arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << getMaxLength(arr, n);
    return 0;
}