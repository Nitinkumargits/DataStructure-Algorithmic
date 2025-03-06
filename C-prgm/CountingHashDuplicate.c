#include <stdio.h>

void DuplicateHash(int A[], int n, int maxVal)
{
    int H[maxVal + 1]; // Hash array initialized to store frequency
    for (int i = 0; i <= maxVal; i++)
    {
        H[i] = 0; // Initialize hash array
    }

    // Store frequency of each element in the hash array
    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    // Print duplicate elements
    printf("Duplicate Elements:\n");
    for (int j = 0; j <= maxVal; j++)
    {
        if (H[j] > 1)
        {
            printf("Element: %d, Count: %d\n", j, H[j]);
        }
    }
}

int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n = sizeof(A) / sizeof(A[0]);
    int maxVal = 20; // Highest value in array for hash size

    DuplicateHash(A, n, maxVal);

    return 0;
}
