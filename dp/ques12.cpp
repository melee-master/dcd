//Rod Cutting Problem:
//Top-Down approach:
#include <iostream>
using namespace std;
int maxProfit(int *prices, int n){
    int dp[10] = {0};
    for(int len=1; len<=n; len++){
        int ans = INT_MIN;
        for(int i=0; i<=len; i++) {
            int cut = i + 1;
            int currentAns = prices[i] + dp[len - cut];
            ans = max(ans, currentAns);
        }
        dp[len] = ans;
    }
    return dp[n];
}
int main(){
    int prices[]= {3, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof (prices) / sizeof (int);
    maxProfit(prices, n);
}