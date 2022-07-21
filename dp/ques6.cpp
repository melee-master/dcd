//coin change problem (Top - Down approach)

#include <iostream>
using namespace std;

int recursiveCall(int n, int coins[], int dp[], int t){
    //Base Case :
    if(n==0){
        return 0;
    }

    if(dp[n]!=0){
        return dp[n];
    }
    //Recursive Case :
    int ans = INT_MAX;
    for(int i=0; i<t; i++){
        if(n-coins[i]>=0) {
            int subProb = recursiveCall(n - coins[i] ,coins, dp, t);
            ans = min(ans, subProb+1);
        }
    }
    return dp[n] = ans;
}
int main(){
    int N=15;
    int coins[] = {1, 7, 10};
    int t  = sizeof (coins) / sizeof (int);
    int dp[100] = {0};
    int ans = recursiveCall(N, coins, dp, t);
    cout<<ans;
}