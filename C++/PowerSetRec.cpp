#include <iostream>
#include <vector>
using namespace std;

void printSet(int index,vector<int> &ds,int arr[],int n){

    if(index==n){
        for(auto it:ds){
            cout<< it<<" ";

        }
        if(ds.size()==0){cout<<"{}";}

        cout<<endl;
        return ;
    }

    ds.push_back(arr[index]);
    printSet(index+1,ds,arr,n);
    ds.pop_back();
    printSet(index+1,ds,arr,n);

}

int main(){
    int arr[]={3,2,1};
    int n=sizeof(arr)/sizeof(arr[1]);
    vector<int> ds;
    printSet(0,ds,arr,n);
    return 0;
}





