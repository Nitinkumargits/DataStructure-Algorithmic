#include <stdio.h>
#include <limits.h>

void maxSubarray(int a[], int n)
{
    int maxSum = INT_MIN, start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
                if (sum > maxSum)
                {
                    maxSum = sum;
                    start = i;
                    end = j;
                }
            }
        }
    }

    printf("Maximum Sum: %d\nSubarray: [", maxSum);
    for (int i = start; i <= end; i++)
    {
        printf("%d", a[i]);
        if (i < end)
            printf(", ");
    }
    printf("]\n");
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxSubarray(arr, n);
    return 0;
}
