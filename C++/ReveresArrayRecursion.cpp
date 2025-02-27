#include <iostream>
using namespace std;

// Recursive function to reverse an array
void reverseArray(int arr[], int start, int end) {
    if (start >= end) return;

    // Swap start and end elements
    swap(arr[start], arr[end]);

    // Recursively reverse the remaining array
    reverseArray(arr, start + 1, end - 1);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void f(int i,int arr[],int n){
    if(i>=n/2) return ;
    swap(arr[i],arr[n-i-1]);
    f(i+1,arr,n);
}

// Driver Code
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    reverseArray(arr, 0, n - 1);

    cout << "Reversed Array: ";
    printArray(arr, n);

    int influx;
    cin>>influx;
    int insertArr[influx];
    for(int i=0;i<n;i++) cin>>insertArr[i];
    f(0,insertArr,influx);
    for(int i=0;i<n;i++) cout<<insertArr[i]<< ' ';
    

    return 0;
}
