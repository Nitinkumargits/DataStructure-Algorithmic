#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> elements;
    for (int num : nums)
    {
        if (elements.find(num) != elements.end())
        {
            return true;
        }
        elements.insert(num);
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 1};
    if (containsDuplicate(nums))
    {
        cout << "Duplicates found in the array." << endl;
    }
    else
    {
        cout << "No duplicates in the array." << endl;
    }

    return 0;
}
