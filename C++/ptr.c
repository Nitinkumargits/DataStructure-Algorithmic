#include <stdlib.h>

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int *p;
    p = &A[0];
    printf("data : %d\n", A);
    printf("pointer : %d ", *p);
}
