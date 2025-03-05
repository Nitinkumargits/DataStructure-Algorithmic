#include <iostream>
#include <stdexcept> // Required for out_of_range exception
using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array(int sz = 10)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Insert(int index, T x);
    T Delete(int index);
};

template <class T>
void Array<T>::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T>::Insert(int index, T x)
{
    if (index >= 0 && index <= length && length < size)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    if (index >= 0 && index < length)
    {
        T x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    throw out_of_range("Index out of range");
}

int main()
{
    Array<int> arr(10);

    arr.Insert(0, 5);
    arr.Insert(1, 6);
    arr.Insert(2, 9);

    arr.Display(); // Output: 5 6 9
    cout << "Deleted: " << arr.Delete(0) << endl;
    arr.Display(); // Output: 6 9

    return 0;
}
