#include <iostream>
#include <algorithm>
using namespace std;

int C2B(int n)
{
    long long binary = 0;
    int place = 1;

    while (n > 0)
    {
        int remainder = n % 2;
        binary += remainder * place;
        place *= 10;
        n /= 2;
    }
    return binary;
}

string Convert2Binary(int n)
{
    string binary = "";
    while (n > 0)
    {
        int res = n % 2;
        if (res == 1)
            binary += '1';
        else
            binary += '0';
        n /= 2;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

int convert2Decimal(string binary)
{
    int num = 0;
    int pw = 1;
    int len = binary.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            num = num + (binary[i] - '0') * pw;
        pw *= 2;
    }
    return num;
}

int main()
{
    int n;
    cout << "Input integer :";
    cin >> n;

    cout << "Binary :" << C2B(n) << endl;
    cout << "Binary stirng :" << Convert2Binary(n) << endl;
    cout << "Decimal :" << convert2Decimal(Convert2Binary(n));

    return 0;
}