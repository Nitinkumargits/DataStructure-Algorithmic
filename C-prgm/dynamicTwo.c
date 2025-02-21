#include <stdio.h>
struct Rectangle
{
    int length;
    int breadth;
    /* data */
};

int main()
{

    struct Rectangle *p = (struct Rectangle *)malloc(3 * sizeof(p));

    p->length = 10;
    p->breadth = 10;

    printf("area : %d", p->length * p->breadth);
    free(p);
    return 0;
}