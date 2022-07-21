//Exchanging Coins:
#include <iostream>
#include <vector>
using namespace std;
int exchangeCoins(int n){
    int dp[100]= {0};
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = max(i, dp[i/2]+dp[i/3]+dp[i/4]);
    }
    return dp[n];
}
int main(){
    int N;
    cin >> N;
    cout<< exchangeCoins(N);
}