#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

double findMedianBrute(int *a, int n, int *b, int m)
{
    int size = n + m;
    int *merged = malloc(size * sizeof(int));
    for (int i = 0; i < n; i++)
        merged[i] = a[i];
    for (int i = 0; i < m; i++)
        merged[n + i] = b[i];
    qsort(merged, size, sizeof(int), compare);

    double result;
    if (size % 2 == 0)
        result = (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    else
        result = merged[size / 2];
    free(merged);
    return result;
}

int main()
{
    int nums1[] = {1, 3}, nums2[] = {2};
    printf("Brute: %.1lf\n", findMedianBrute(nums1, 2, nums2, 1));
    return 0;
}
