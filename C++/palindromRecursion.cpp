#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    if (start >= end) return true;  // Base case: Single or no characters left
    
    if (s[start] != s[end]) return false;  // Mismatch found
    
    return isPalindrome(s, start + 1, end - 1);  // Recursive check for inner substring
}

bool isp(int i,string s,int n){
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]) return false;

    isp(i+1,s,n);
}


int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    
    int n=str.length();
    cout<<isp(0,str,n)<<endl;


    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}
