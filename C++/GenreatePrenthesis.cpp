#include <iostream>
#include <vector>

using namespace std;

void generateParenthesesHelper(int open, int close, int n, string current, vector<string> &result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // Add '(' if we have not used all opening brackets
    if (open < n) {
        generateParenthesesHelper(open + 1, close, n, current + "(", result);
    }

    // Add ')' if it does not exceed the number of '('
    if (close < open) {
        generateParenthesesHelper(open, close + 1, n, current + ")", result);
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    generateParenthesesHelper(0, 0, n, "", result);
    return result;
}

int main() {
    int n = 4;
    vector<string> result = generateParentheses(n);

    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
