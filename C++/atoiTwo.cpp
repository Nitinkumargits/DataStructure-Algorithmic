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

int atoi(string str)
{
    // Your code here
    int result = 0;    // Stores and returns the integer converted value for str
    int i = 0;         // just a current character pointer for string
    int sign = 1;      // multiplied at the end to result to determine if the string is +ve or -ve
    if (str[i] == '-') // Check the sign of string (+ or -)
    {
        sign = -1;
        i++;
    }
    // Now traverse the entire string and convert it into integer
    while (str[i])
    {
        // If any character is not an integer then just return -1
        if (!(str[i] - '0' >= 0 && str[i] - '0' <= 9))
            return -1;
        // else just keep updating the result
        result = result * 10 + str[i] - '0';
        i++;
    }
    return result * sign;
}