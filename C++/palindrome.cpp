#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }

private:
    void func(int index, string &s, vector<string> &path, vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

// Driver Code
int main()
{
    Solution sol;
    string s = "aabb";
    vector<vector<string>> result = sol.partition(s);

    cout << "Palindrome Partitions:\n";
    for (auto &partition : result)
    {
        for (auto &str : partition)
        {
            cout << "\"" << str << "\" ";
        }
        cout << endl;
    }

    return 0;
}
