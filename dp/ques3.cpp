//Minimum steps to one:
//Top Down approach:
#include <iostream>
#include <limits>
using namespace std;
int recursiveCall(int n, int dp[]){
    if(n==1){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int op1 = INT_MAX;
    int op2 = INT_MAX;
    int op3 = INT_MAX;
    if(n%3 == 0){
        op1 = recursiveCall(n/3, dp) +1;
    }
    if(n%2 == 0){
        op2 = recursiveCall(n/2, dp)+1;
    }
    op3 = recursiveCall(n-1, dp)+1;
    int ans = min(min(op1, op2), op3);
    dp[n] = ans;
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int dp[100]={0};
    int  y = recursiveCall(n, dp);
    cout<<y;
    return 0;
}