#include <iostream>
#include <unordered_map>
using namespace std;

int numOfSubstring(string s)
{

    unordered_map<char, int> count;

    int left = 0, result = 0, n = s.length();

    for (int right = 0; right < n; right++)
    {
        count[s[right]]++;

        while (count['a'] > 0 && count['b'] > 0 && count['c'] > 0)
        {
            /* code */
            result += (n - right);
            count[s[left]]--;
            left++;
        }
    }
    return result;
}

int main()
{
    string s = "bbacba";
    cout << numOfSubstring(s) << endl;
}