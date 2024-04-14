#include <stdio.h>

int main()
{
    int r, n, sum = 0;
    scanf("%d", &n);
    int m = n;
    while (n > 0)
    {
        r = n % 10;
        n /= 10;
        sum = sum + r * r * r;
    }
    if (sum == m)
    {
        printf("it's Armstrong ");
    }
}