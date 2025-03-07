#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[m->n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++) // Fixed loop condition
    {
        for (j = 1; j <= m.n; j++) // Fixed loop condition
        {
            if (i >= j)
            {
                printf("%d ", m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
            }
            else
            {
                printf("0 "); // Fixed missing semicolon
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int i, j, x;
    printf("Enter Dimension: ");
    scanf("%d", &m.n); // Removed space in "%d"

    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Enter all elements:\n");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= i; j++) // Loop correctly for lower triangular input
        {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    printf("\nMatrix Representation:\n");
    Display(m);

    free(m.A); // Free allocated memory
    return 0;  // Fixed missing semicolon
}
