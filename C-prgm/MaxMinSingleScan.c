#include <stdio.h>

void MaxMin(int A[], int n)
{
    int min = A[0];
    int max = A[0];

    for (int i = 1; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        else if (A[i] > max)
        {
            max = A[i];
        }
    }
    printf("Max : %d\nMin : %d", max, min);
}

int main()
{
    int A[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4, 16};
    int n = sizeof(A) / sizeof(A[0]);

    MaxMin(A, n);
    return 0;
}