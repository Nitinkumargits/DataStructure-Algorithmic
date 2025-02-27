#include <iostream>
using namespace std;

void f(int i, int arr[], int n) {
    if (i >= n / 2) return;
    
    swap(arr[i], arr[n - i - 1]);
    f(i + 1, arr, n);
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];  // Array of size n
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input elements
    }

    f(0, arr, n);  // Fix: Add missing semicolon

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Print array after reversing
    }
    cout << endl;  // Fix formatting

    return 0;
}
