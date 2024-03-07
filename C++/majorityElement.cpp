#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1;

    for (int i = 0; i < n; i++)
    {

        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            // update maxCount if count of
            // Current element is greater
            if (count > maxCount)
            {
                maxCount = count;
                index = i;
            }
        }

        // if maxcount is greater than n/2
    }
    // return the corresponding element
    if (maxCount > n / 2)
    {
        cout << arr[index] << endl;
    }
    else
    {
        cout << "No majority element" << endl;
    }
}

int main()
{
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMajority(arr, n);

    return 0;
}