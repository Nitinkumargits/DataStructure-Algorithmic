#include <stdlib.h>
struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r;
    // r.length = 10;
    // r.breadth = 20;
    // printf("%d %d ", r.length, r.breadth);
    // struct Rectangle *p = &r;
    // p->length = 40;
    // p->breadth = 39;
    // printf("%d %d\n", p->length, p->breadth);
    // printf("%d", *p);
    // Dynamically allocated
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 9;
    p->breadth = 899;
    printf("%d %d\n", p->length, p->breadth);
}