#include <stdio.h>
struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r = {10, 15};

    r.length = 3;
    r.breadth = 4;

    printf("Area : %d", r.length * r.breadth);
}