#include <stdlib.h>

struct Rectangle
{
    int length;
    int breath;
};

int main()
{
    struct Rectangle r;
    r.length = 2;
    r.breath = 5;
    printf("%d", r.length * r.breath);
}