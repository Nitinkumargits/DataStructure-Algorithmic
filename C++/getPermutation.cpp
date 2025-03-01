#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;

        // Compute (n-1)! and store numbers from 1 to n
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n); // Last number

        string ans = "";
        k--; // Convert k to 0-based index

        while (!numbers.empty())
        {
            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);

            if (numbers.empty())
                break;

            k %= fact;
            fact /= numbers.size();
        }

        return ans;
    }
};

// Driver Code
int main()
{
    Solution sol;
    int n = 4, k = 9;
    cout << "K-th Permutation: " << sol.getPermutation(n, k) << endl;
    return 0;
}
