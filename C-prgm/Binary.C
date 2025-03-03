#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Iterative Binary Search
int BinarySearch(struct Array arr, int key)
{
    int l = 0, h = arr.length - 1, mid;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

// Recursive Binary Search
int RecBinarySearch(int A[], int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            return RecBinarySearch(A, l, mid - 1, key);
        else
            return RecBinarySearch(A, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    struct Array arr = {{1, 3, 5, 7, 9, 11}, 10, 6};

    int key = 7;
    printf("Iterative Binary Search: Element found at index %d\n", BinarySearch(arr, key));
    printf("Recursive Binary Search: Element found at index %d\n", RecBinarySearch(arr.A, 0, arr.length - 1, key));

    return 0;
}
