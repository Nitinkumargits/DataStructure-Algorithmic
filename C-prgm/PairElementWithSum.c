#include <stdio.h>

void PairElement(int A[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) // Fixed increment issue
        {
            if (A[i] + A[j] == k)
            {
                printf("%d + %d = %d\n", A[i], A[j], k);
            }
        }
    }
}

void PairElementHashing(int A[], int n, int k, int maxVal)
{
    int hash[maxVal + 1]; // Create hash table
    for (int i = 0; i <= maxVal; i++)
    {
        hash[i] = 0; // Initialize hash table
    }

    for (int i = 0; i < n; i++)
    {
        if (k - A[i] >= 0 && hash[k - A[i]] != 0) // Fixed condition
        {
            printf("%d + %d = %d\n", A[i], k - A[i], k);
        }
        hash[A[i]]++; // Store element in hash
    }
}

int main()
{
    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 10;

    printf("Brute Force Approach:\n");
    PairElement(A, n, k);

    printf("\nHashing Approach:\n");
    PairElementHashing(A, n, k, 16);

    return 0;
}
