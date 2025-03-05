#include <stdio.h>

void MissingElements(int A[], int n, int low, int high)
{
    int H[high + 1]; // Create hash table up to the highest value
    for (int i = 0; i <= high; i++)
        H[i] = 0; // Initialize hash table with zeros

    // Populate the hash table
    for (int i = 0; i < n; i++)
    {
        H[A[i]] = 1; // Mark present elements
    }

    // Identify and print missing elements
    printf("Missing elements:\n");
    for (int i = low; i <= high; i++)
    {
        if (H[i] == 0)
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    int A[] = {1, 2, 4, 5, 7, 9}; // Example array
    int n = sizeof(A) / sizeof(A[0]);
    int low = 1, high = 9; // Range of elements

    MissingElements(A, n, low, high);

    return 0;
}

// Missing elements : 3 6 8
