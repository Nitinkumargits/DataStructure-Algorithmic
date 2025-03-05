#include <stdio.h>

void singleMissingElement(int arr[], int n)
{
    int l = arr[0]; // First element in the array
    int difference = l - 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != difference)
        {
            printf("Missing element: %d\n", i + difference);
            break; // Since only one missing element is expected, break the loop
        }
    }
}

void MultipleElement(int arr[], int n)
{
    int diff = arr[0] - 0; // Initialize difference

    for (int i = 0; i < n; i++)
    {
        while (diff < arr[i] - i) // Print missing elements until diff matches
        {
            printf("Missing element: %d\n", i + diff);
            diff++;
        }
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 6}; // Example: Single missing element (5)
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 2, 4, 5, 7, 9}; // Example: Multiple missing elements (3, 6, 8)
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Single Missing Element:\n");
    singleMissingElement(arr1, n1);

    printf("\nMultiple Missing Elements:\n");
    MultipleElement(arr2, n2);

    return 0;
}
Single Missing Element : Missing element : 5

                         Multiple Missing Elements : Missing element : 3 Missing element : 6 Missing element : 8
