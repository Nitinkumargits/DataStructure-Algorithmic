
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

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int sum(struct Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
}

float Avg(struct Array arr)
{
    return (float)sum(arr) / arr.length;
}

int main()
{
    struct Array arr = {{2, 3, 10, 5, 6}, 10, 5};
    printf("Array elements: ");
    Display(arr);

    printf("Element at index 2: %d\n", Get(arr, 2));
    Set(&arr, 2, 8);
    printf("Updated array: ");
    Display(arr);

    printf("Max: %d\n", max(arr));
    printf("Min: %d\n", min(arr));
    printf("Sum: %d\n", sum(arr));
    printf("Average: %.2f\n", Avg(arr));

    return 0;
}
