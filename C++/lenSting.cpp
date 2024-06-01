#include <iostream>
#include <string>
using namespace std;
int stringLength(const string &str)
{
    if (str.empty())
    {
        return 0;
    }
    return 1 + stringLength(str.substr(1));
}
int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int length = stringLength(input);
    cout << "Length of the string: " << length << endl;
    return 0;
}