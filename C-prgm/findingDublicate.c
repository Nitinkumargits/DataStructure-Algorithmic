#include <stdio.h>

void Duplicate(int A[], int n)
{
    int lastDuplicate = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate)
        {
            printf("%d\n", A[i]);
            lastDuplicate = A[i];
        }
    }
}

void CountingDuplicate(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            int j = i + 1;
            while (A[j] == A[i])
            {
                j++;
            }
            printf("%d is appearing %d times.\n", A[i], j - i);
            i = j - 1;
        }
    }
}

int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n = sizeof(A) / sizeof(A[0]);

    Duplicate(A, n);
    CountingDuplicate(A, n);
    return 0;
}