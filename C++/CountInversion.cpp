#include <iostream>
#include <vector>

using namespace std;

int Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;

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
            count += (mid - left + 1); // Counting inversions
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

    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;

    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += Merge(arr, low, mid, high);

    return count;
}

int numberOfInversions(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}

// Driver code
int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    int n = arr.size();
    cout << "Number of Inversions: " << numberOfInversions(arr, n) << endl;
    return 0;
}
