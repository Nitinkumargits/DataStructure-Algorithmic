#include <stdio.h>

struct Matrix
{
    int A[10]; // Array for storing diagonal elements
    int n;     // Size of the matrix
};

// Function to set a diagonal element
void set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
    {
        m->A[i - 1] = x; // Store only diagonal elements
    }
}

// Function to get a matrix element
int Get(struct Matrix m, int i, int j)
{
    if (i == j)
    {
        return m.A[i - 1]; // Return diagonal element
    }
    else
    {
        return 0; // Non-diagonal elements are 0
    }
}

// Function to display the diagonal matrix
void Display(struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
            {
                printf("%d ", m.A[i]); // Corrected index access
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Main function to test the implementation
int main()
{
    struct Matrix m;
    m.n = 4;

    // Initialize diagonal elements
    set(&m, 1, 1, 5);
    set(&m, 2, 2, 8);
    set(&m, 3, 3, 9);
    set(&m, 4, 4, 12);

    // Test get function
    printf("Element at (2,2): %d\n", Get(m, 2, 2));

    // Display the matrix
    printf("Diagonal Matrix:\n");
    Display(m);

    return 0;
}
