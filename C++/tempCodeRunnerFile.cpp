#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int num)
{
    if (st.empty())
    {
        st.push(num);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st, num);
    st.push(top);
}

// Recursive function to reverse the stack
void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
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
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);

    reverseStack(st);
    printStack(st); // Output: 6 7 1 2 3

    return 0;
}
