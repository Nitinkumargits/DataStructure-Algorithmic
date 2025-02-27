#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int> &arr, int low, int high)
{
    if (low >= high) // Fix: Change `low == high` to `low >= high`
        return;

    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr)
{
    mS(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {3, 1, 2, 4, 5, 6, 2, 4}; // Fix: Use vector<int>
    mergeSort(arr);                             // Fix: Correct function call

    // Print sorted array
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
