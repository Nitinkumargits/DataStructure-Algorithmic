#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElements: ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        { // Equal elements, add only once
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    while (i < arr1->length)
    {
        arr3->A[k++] = arr1->A[i++];
    }
    while (j < arr2->length)
    {
        arr3->A[k++] = arr2->A[j++];
    }

    arr3->length = k;
    arr3->size = 20;
    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        { // Common element
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 20;
    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        { // Common elements are ignored
            i++;
            j++;
        }
    }

    while (i < arr1->length)
    {
        arr3->A[k++] = arr1->A[i++];
    }

    arr3->length = k;
    arr3->size = 20;
    return arr3;
}

int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 20, 5};
    struct Array arr2 = {{4, 6, 10, 14, 20}, 20, 5};

    struct Array *arr3;

    printf("Union:");
    arr3 = Union(&arr1, &arr2);
    Display(*arr3);

    printf("\nIntersection:");
    arr3 = Intersection(&arr1, &arr2);
    Display(*arr3);

    printf("\nDifference (arr1 - arr2):");
    arr3 = Difference(&arr1, &arr2);
    Display(*arr3);

    free(arr3);
    return 0;
}
