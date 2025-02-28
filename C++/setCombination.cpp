#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

for (int i = index; i < arr.size(); i++) {
   if (i > index && arr[i] == arr[i - 1]) continue; // Skip duplicates
            if (arr[i] > target) break;
            
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
int main() {
    Solution obj;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

vector<vector<int>> result = obj.combinationSum2(candidates, target);

    for (auto subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
