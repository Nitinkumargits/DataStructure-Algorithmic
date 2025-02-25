#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to count distinct subsequences using DP
int distinctSubsequences(string s) {
    int n = s.length();
    vector<int> dp(n + 1, 0);
    unordered_map<char, int> last_occurrence;

    dp[0] = 1; // Empty string has one subsequence

    for (int i = 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1];

        char ch = s[i - 1];
        if (last_occurrence.find(ch) != last_occurrence.end()) {
            dp[i] -= dp[last_occurrence[ch] - 1]; // Remove duplicate subsequences
        }

        last_occurrence[ch] = i; // Update last occurrence
    }

    return dp[n];
}

// Function to return the better string
string betterString(string str1, string str2) {
    int count1 = distinctSubsequences(str1);
    int count2 = distinctSubsequences(str2);

    return (count1 >= count2) ? str1 : str2;
}

// Driver code
int main() {
    string str1 = "gfg", str2 = "ggg";
    cout << betterString(str1, str2) << endl; // Output: "gfg"

    str1 = "a", str2 = "b";
    cout << betterString(str1, str2) << endl; // Output: "a"

    return 0;
}
