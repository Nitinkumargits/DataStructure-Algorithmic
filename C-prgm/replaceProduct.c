#include <stdio.h>

// Function to replace each array element with every other
// element's product without using the division operator
void findProduct(int arr[], int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // use two auxiliary arrays
    int left[n], right[n];

    // `left[i]` stores the product of all elements in subarray[0…i-1]
    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = arr[i - 1] * left[i - 1];
    }

    // `right[i]` stores the product of all elements in subarray[i+1…n-1]
    right[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--)
    {
        right[j] = arr[j + 1] * right[j + 1];
    }

    // replace each element with the product of its left and right subarray
    for (int i = 0; i < n; i++)
    {
        arr[i] = left[i] * right[i];
    }
}

int main(void)
{
    int arr[] = {5, 3, 4, 2, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    findProduct(arr, n);

    // print the modified array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
