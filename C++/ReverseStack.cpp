#include <iostream>
#include <stack>
#include <vector>

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

// Function to print the stack without modifying it
void printStack(stack<int> st)
{
    vector<int> temp;

    // Store elements in a temporary array to maintain order
    while (!st.empty())
    {
        temp.push_back(st.top());
        st.pop();
    }

    // Print elements in the correct order
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        cout << temp[i] << " ";
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

    // Print reversed stack in correct order
    printStack(st); // Correct Output: 6 7 1 2 3

    return 0;
}

void printStack(stack<int> st)
{
    vector<int> temp; // Temporary vector to store stack elements

    // Step 1: Transfer elements from stack to vector
    while (!st.empty())
    {
        temp.push_back(st.top()); // Store the top element in the vector
        st.pop();                 // Remove the top element from the stack
    }

    // Step 2: Print elements in correct order (from bottom to top)
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        cout << temp[i] << " "; // Print elements in original order
    }
    cout << endl;
}
void printStackRecursive(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();

    printStackRecursive(st); // Recursive call to print remaining elements

    cout << top << " "; // Print after recursion (preserves order)

    st.push(top); // Push back to restore original stack
}
