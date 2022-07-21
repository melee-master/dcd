//coin-change problem (Bottom - Up approach)
#include <iostream>
using namespace std;
int recursiveCall(int coins[], int N, int T){
    int dp[100] = {0};
    for(int n=1; n<=N ; n++){
        dp[n] = INT_MAX;
        for(int i=0; i<T; i++){
            if (n - coins[i]>= 0){
                int subProb = dp[n-coins[i]];
                dp[n] = min(dp[n], subProb+1);
            }
        }
    }
    return dp[N];
}
int main(){
    int N=15;
    int coins[] = {1, 7, 10};
    int t  = sizeof (coins) / sizeof (int);
    int ans = recursiveCall(coins, N, t);
    cout<<ans;
    return 0;
}