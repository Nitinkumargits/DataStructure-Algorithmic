
#include <stdio.h>

void DuplicateUnsortedArray(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < n; j++) // Fixed loop condition
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1; // Mark as visited
                }
            }
        }
        if (count > 1)
        {
            printf("Element %d appears %d times\n", A[i], count);
        }
    }
}

int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n = sizeof(A) / sizeof(A[0]);

    DuplicateUnsortedArray(A, n);

    return 0;
}
