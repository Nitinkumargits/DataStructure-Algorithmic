#include <stdlib.h>

struct Rectagle
{
    int len;
    int brth;
};

int main()
{
    struct Rectagle r = {1, 2};
    struct Rectagle *p;
    p->len = 15;
    p->brth = 12;
}
