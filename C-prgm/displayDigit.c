#include <stdio.h>

int main()
{
    int n = 2753, r, cout = 0;
    // while (n > 0)
    // {
    //     r = n % 10; /// last ki digit alag krne ke liye
    //     n = n / 10; // last se ek digit kam krne keliye
    //     printf("%d\n", r);
    // }

    while (n > 0)
    {
        r = n % 10;
        n = n / 10;
        cout++;
        // printf("%d\n", r);
    }
    printf("number :%d\n", cout);
}