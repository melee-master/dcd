#include <iostream>
#include <climits>
using namespace std;
int dp[1005][1005];
int knapsack(int n, int cap, int *val, int *wt){
    //Base Case:
    if(n==0 || cap==0){
        return 0;
    }
    if(dp[n][cap]!=-1){
        return dp[n][cap];
    }
    //Recursive Case:
    int notTake = knapsack(n-1, cap, val, wt);
    int take = INT_MIN;
    if(cap>=wt[n-1]){
        take = knapsack(n-1, cap-wt[n-1], val, wt) + val[n-1];
    }
    return dp[n][cap] = max(take, notTake);
}
int main(){
    int n;
    int cap;
    cin>>n>>cap;
    int wt[n];
    int val[n];
    for(int i=0;i <n; i++){
        cin>>wt[i];
    }
    for(int i=0; i<n ;i++){
        cin>>val[i];
    }
    memset(dp, -1, sizeof dp);
    cout<<knapsack(n, cap, val, wt);
}