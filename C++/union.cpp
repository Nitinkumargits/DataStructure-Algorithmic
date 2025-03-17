#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> &a, vector<int> &b)
{
    set<int> st;

    for (int num : a)
        st.insert(num);
    for (int num : b)
        st.insert(num);

    vector<int> result(st.begin(), st.end());
    return result;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 6, 7, 8};

    vector<int> result = sortedArray(a, b);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
