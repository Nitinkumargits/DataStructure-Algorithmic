#include <stdio.h>
#include <stdlib.h>

void findUniqueElement(int arr[], int size)
{
    int freq[1000] = {0};

    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }

    printf("Unique Element :");
    for (int i = 0; i < size; i++)
    {
        if (freq[arr[i]] == 1)
            printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {4, 3, 2, 4, 1, 3, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    findUniqueElement(arr, size);
    return 0;
}