#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Reverse using auxiliary array
void Reverse(struct Array *arr)
{
    int *B = (int *)malloc(arr->length * sizeof(int));
    int i, j;
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
    free(B);
}

// Reverse by swapping
void ReverseSwap(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};

    printf("Original Array: ");
    Display(arr);

    Reverse(&arr);
    printf("Reversed using auxiliary array: ");
    Display(arr);

    ReverseSwap(&arr);
    printf("Reversed back using swapping method: ");
    Display(arr);

    return 0;
}
