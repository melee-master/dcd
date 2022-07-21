#include<iostream>
using namespace std;
 
int dp[10000][10000];
int gameStrategy(int s, int e, int *arr){
    if(s>e){
        return 0;
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    //Recursive Case :
    int op1 = arr[s] + min(gameStrategy(s+2, e, arr), gameStrategy(s+1, e-1, arr));
    int op2 = arr[e] + min(gameStrategy(s+1, e-1, arr), gameStrategy(s, e-2, arr));
    dp[s][e] = max(op1, op2);
    return dp[s][e];
}
int main(){
    memset(dp, -1, sizeof dp);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<gameStrategy(0, n-1, arr);
}