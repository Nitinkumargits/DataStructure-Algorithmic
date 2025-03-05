#include <stdio.h>

void findingMissingElement(int arr[], int n)
{
    int sum = 0;

    // Calculate sum of given elements
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // Expected sum of first (n+1) natural numbers
    int expectedSum = (n + 1) * (n + 2) / 2;

    // Print missing element
    printf("Missing element: %d\n", expectedSum - sum);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6}; // Example: Missing number is 4
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("size %d\n ", n);

    findingMissingElement(arr, n);

    return 0;
}
