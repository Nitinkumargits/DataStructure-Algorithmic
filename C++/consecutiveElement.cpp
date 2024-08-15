#include <stdio.h>

// Utility function to swap elements `A[i]` and `A[j]` in an array
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Utility function to find a minimum of two numbers
int min(int x, int y)
{
    return (x < y) ? x : y;
}

// Utility function to reverse subarray `arr[i, j]`
void reverse_subarray(int arr[], int i, int j)
{
    while (i < j)
    {
        swap(arr, i, j);
        i++, j--;
    }
}

// Function to reverse every consecutive `m` elements of
// subarray `arr[beg, end]`
void reverse(int arr[], int beg, int end, int m)
{
    // base case
    if (m <= 1)
    {
        return;
    }

    // return if the subarray length is less than `m`
    if (m > end - beg + 1)
    {
        return;
    }

    // reverse every consecutive `m` elements
    for (int i = beg; i <= end; i = i + m)
    {
        // check if subarray length is at least `m`
        if (i + m - 1 <= end)
        {
            reverse_subarray(arr, i, i + m - 1);
        }
    }
}

// Utility function to print given array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = 3;
    int beg = 1, end = 8;

    int n = sizeof(arr) / sizeof(arr[0]);

    // reverse the array
    reverse(arr, beg, min(end, n - 1), m);

    // print the modified array
    printArray(arr, n);

    return 0;
}
