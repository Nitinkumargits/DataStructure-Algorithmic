#include <iostream>
#include <algorithm> // For reverse()
using namespace std;

string convert2Binary(int n)
{
    if (n == 0)
        return "0"; // Edge case

    string res = "";

    while (n > 0)
    {
        res += (n % 2 == 0 ? "0" : "1"); // Append binary digit
        n /= 2;                          // Update n
    }

    reverse(res.begin(), res.end()); // Reverse to get correct order
    return res;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Binary representation: " << convert2Binary(num) << endl;
    return 0;
}
