//Fibonacci top-down approach:
#include <iostream>
using namespace std;
int fib(int n, int dp[]){
    //Base Case:
    if(n==0 || n==1){
        return n;
    }
    //Lookup:
     if(dp[n]!=0){
         return dp[n];
     }
    //Recursive Case :
    int ans = fib(n-1, dp) + fib(n-2, dp);
    dp[n] = ans;
    return ans;
}



int main(){
    int n;
    cin>>n;
    int dp[100] = {0};
    int ans = fib(n, dp);
    cout<<ans;
    return 0;
}


