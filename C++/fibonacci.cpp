#include <iostream>
using namespace std;
class GFG{
    public:
      int fib(int n);

};
GFG::fib(int n){
        int i;
        int f[n+2];
        f[0]=0;
        f[1]=1;
        for( i=2;i<=n;i++){
            f[i]=f[i-1]+f[i-2];
        }
        return f[i];
      };

int main(){
    GFG g;
    int n=9;
   cout<< g.fib(n)<<" ";
}