#include <bits/stdc++.h>
using namespace std;

void reverse(string str)
{
	for (int i = str.length() - 1; i >= 0; i--)
		cout << str[i];
}

// Driver code
int main(void)
{
	string s = "GeeksforGeeks";
	reverse(s);
	return (0);
}
