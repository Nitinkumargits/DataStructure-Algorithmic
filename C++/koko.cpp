#include <stdio.h>
#include <math.h>

// Brute Force Approach
int canEatAll(int piles[], int n, int h, int k)
{
    int hours = 0;
    for (int i = 0; i < n; i++)
    {
        hours += ceil((double)piles[i] / k);
    }
    return hours <= h;
}

int minEatingSpeedBrute(int piles[], int n, int h)
{
    int max_pile = 0;
    for (int i = 0; i < n; i++)
        if (piles[i] > max_pile)
            max_pile = piles[i];

    for (int k = 1; k <= max_pile; k++)
    {
        if (canEatAll(piles, n, h, k))
            return k;
    }
    return max_pile;
}

// Optimal - Binary Search
int minEatingSpeedOptimal(int piles[], int n, int h)
{
    int left = 1, right = 0, ans;
    for (int i = 0; i < n; i++)
        if (piles[i] > right)
            right = piles[i];

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canEatAll(piles, n, h, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int piles[] = {3, 6, 7, 11};
    int h = 8;
    int n = sizeof(piles) / sizeof(piles[0]);

    printf("Brute Force Min Eating Speed: %d\n", minEatingSpeedBrute(piles, n, h));
    printf("Optimal Min Eating Speed: %d\n", minEatingSpeedOptimal(piles, n, h));

    return 0;
}
