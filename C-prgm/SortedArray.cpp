
#include <iostream>
#include <vector>

using namespace std;

class Array
{
public:
    vector<int> A;
    int size;
    int length;

    Array(vector<int> arr, int sz)
    {
        A = arr;
        size = sz;
        length = arr.size();
    }

    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

Array merge(Array arr1, Array arr2)
{
    vector<int> merged;
    int i = 0, j = 0;

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            merged.push_back(arr1.A[i++]);
        }
        else
        {
            merged.push_back(arr2.A[j++]);
        }
    }

    while (i < arr1.length)
    {
        merged.push_back(arr1.A[i++]);
    }

    while (j < arr2.length)
    {
        merged.push_back(arr2.A[j++]);
    }

    return Array(merged, arr1.size + arr2.size);
}

int main()
{
    Array arr1({2, 6, 10, 15, 25}, 10);
    Array arr2({4, 12, 14, 20, 22}, 10);

    cout << "Merged Array: ";
    Array arr3 = merge(arr1, arr2);
    arr3.display();

    return 0;
}