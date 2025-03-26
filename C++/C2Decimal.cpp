#include <iostream>
using namespace std;

int ConvertToDecimal(string s)
{
    int len = s.length();
    int pw = 1;
    int num = 0;

    if (len == 0)
        return 0; // Handle empty string case

    for (int i = len - 1; i >= 0; i--)
    {
        num += (s[i] - '0') * pw; // Convert char to int and multiply by power of 2
        pw *= 2;
    }

    return num;
}

int main()
{
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    cout << "Decimal equivalent: " << ConvertToDecimal(binary) << endl;
    return 0;
}
