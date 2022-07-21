#include <iostream>
using namespace std;
int coinChange(int s[], int n, int m, int dp[1000][1000]){
    if(m==0){
        return dp[n][m] = 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s[n-1]<=m){
        return dp[n][m] = coinChange(s, n, m-s[n-1], dp) + coinChange(s, n-1, m, dp);
    }else{
        return dp[n][m] = coinChange(s, n-1, m, dp);
    }


}
int main(){

    int t;
    cin>>t;
    int dp[1000][1000];

    while(t>0){
        memset(dp, -1, sizeof (dp));
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int m;
        cin>>m;
        cout<<coinChange(arr, n, m, dp)<<endl;
        t--;
    }


}