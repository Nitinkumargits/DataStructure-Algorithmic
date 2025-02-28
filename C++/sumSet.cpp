
#include <bits/stdc++.h>

class Solution{

    public :
    void func(int index,int sum,vector<int> &arr,int N,vector<int> &sumSubset){
        if(index==N){
            sumSubset.push_back(sum);
            return;
        }

        // pick
        func(ind+1,sum+arr[index],arr,N,sumSubset);
        //donot pick
        func(ind+1,sum,arr,N,sumSubset);
    }

    public:
    vector<int> subsetSums(vector<int> arr,int N){
        vector<int> sumSubset;
        func(0,0,arr,N,sumSubset);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    }
}