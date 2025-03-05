#include <stdio.h>

void findingMissingElement(int arr[], int n)
{
    int sum = 0;

    // Calculate the sum of given elements
    for (int i = 0; i < n + 1; i++)
    {
        sum += arr[i];
    }

    printf("%d\n", arr[n - 1]);

    // Calculate the expected sum of 1 to N numbers
    int expectedSum = arr[n - 1] * (n + 2) / 2;

    // Find the missing number
    int missingNumber = expectedSum - sum;

    printf("Missing number is %d\n", missingNumber);
}

int main()
{
    int arr[] = {1, 2, 3, 5};

    // Example: Missing number is 5
    int n = sizeof(arr) / sizeof(arr[0]); // Find the size of the array: 5

    findingMissingElement(arr, n);

    return 0;
}
