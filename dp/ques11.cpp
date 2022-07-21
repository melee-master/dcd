//Ladders - Bottom up approach:
#include <iostream>
using namespace std;
int stepsBottomUp(int n, int k){
    int dp[10] = {0};
    dp[0] = 1;
    for(int i=1; i<=n; i++){

        for(int j=1; j<=k; j++) {
            if(i-j>=0){
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}




int main(){

    int ans = stepsBottomUp(4, 3);
    cout<<ans;

}