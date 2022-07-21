#include <iostream>
using namespace std;
int dp[1005][1005];
int plateDrop(int n, int k, int dp[1005][1005]){
    //Base Case :
    if(n==0  || n==1){
        return n;
    }
    if(k==1){
        return n;
    }
    //Look up:
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    //Recursive Case:
    int result  = INT_MAX;
    for(int i=1; i<=n; i++) {
        int subProb = max(plateDrop(i-1, k-1, dp), plateDrop(n-i, k, dp));
        result = min(result, subProb);
    }
    return dp[n][k] = result+1;
}



int main(){
    int t;
    cin>>t;
    while(t>0){
        int k, n;
        cin>>k>>n;
        memset(dp, -1, sizeof (dp));
        cout<<plateDrop(n, k, dp)<< endl;
        t--;
    }
}