#include <iostream>

using namespace std;

void toi(int n, char A, char B, char C)
{
    // Base case: Stop recursion when n is 0
    if (n == 0)
        return;

    // Move (n-1) disks from A to B using C as auxiliary
    toi(n - 1, A, C, B);

    // Move the nth disk from A to C
    cout << "Move disk " << n << " from " << A << " to " << C << endl;

    // Move (n-1) disks from B to C using A as auxiliary
    toi(n - 1, B, A, C);
}

int main()
{
    int n = 4;             // Number of disks
    toi(n, 'A', 'B', 'C'); // Solve Tower of Hanoi for 4 disks
    return 0;
}
