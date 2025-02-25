#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element into a sorted stack
void sortedInsert(stack<int> &st, int num)
{
    if (st.empty() || st.top() <= num)
    {
        st.push(num);
        return;
    }

    int top = st.top();
    st.pop();
    sortedInsert(st, num);
    st.push(top);
}

// Recursive function to sort the stack
void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, top);
}

// Helper function to print the stack
void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(11);
    st.push(1);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(41);

    sortStack(st);
    printStack(st); // Output: 41 32 11 3 2

    return 0;
}
