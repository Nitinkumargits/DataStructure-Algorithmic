#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Display(struct Array arr)
{
    int i;
    printf("\nElements: ");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}
int linearSearchTransposition(struct Array *arr, int key)
{

    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }

    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 33}, 10, 5};
    printf("%d\n", linearSearchTransposition(&arr, 33));
    printf("%d\n", linearSearchTransposition(&arr, 33));
    printf("%d\n", linearSearchTransposition(&arr, 33));
    printf("%d\n", linearSearchTransposition(&arr, 33));
    Display(arr);
}