#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string s)
{
    int i = 0, sign = 1;
    long result = 0; // Using long to handle overflow before clamping

    // Step 1: Ignore leading whitespace
    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }

    // Step 2: Handle optional sign
    if (i < s.length() && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Convert digits to integer
    while (i < s.length() && isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');

        // Step 4: Handle 32-bit integer overflow
        if (result * sign < INT_MIN)
            return INT_MIN;
        if (result * sign > INT_MAX)
            return INT_MAX;

        i++;
    }

    return result * sign;
}

int main()
{
    string s = "   -42";
    cout << myAtoi(s) << endl; // Output: -42

    s = "4193 with words";
    cout << myAtoi(s) << endl; // Output: 4193

    s = "words and 987";
    cout << myAtoi(s) << endl; // Output: 0

    s = "-91283472332";
    cout << myAtoi(s) << endl; // Output: -2147483648 (clamped)

    s = "1337c0d3";
    cout << myAtoi(s) << endl; // Output: -2147483648 (clamped)
    return 0;
}
