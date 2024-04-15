#include <iostream>
#include <bits/stdc++.h>
using namespace std;
  bool isSqureRoot(int n){
        int s=sqrt(n);
        return (s*s== n);
    }
   bool isFibonacci(int n){
        return isSqureRoot(5*n*n+4)||isSqureRoot(5*n*n-4);
    }

int main(){
    
   for(int i=1;i<=10;i++){
 isFibonacci(i)?cout<<i<<" IS fibo\n":cout<<i<<" NOT fibo\n";
   }
    
}
