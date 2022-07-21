//wines problem top-Down;
#include <iostream>
using namespace std;
int recursiveCall(int *p, int y, int s, int e, int dp[100][100]){
    //Base Case :
    if(s>e){
        return 0;
    }
    if(dp[s][e]!=0){
        return dp[s][e];
    }
    //Recursive Case :
    int profit = max((y*p[s]+ recursiveCall(p, y+1, s+1, e, dp)), (y*p[e]+ recursiveCall(p, y+1, s, e-1, dp)));
    dp[s][e] = profit;
    return profit;
}
int main(){
    int wines[] = {2, 3, 5, 1, 4};
    int n = sizeof (wines) / sizeof (int);
    int dp[100][100] = {0};
    int ans = recursiveCall(wines, 1, 0, n-1, dp);
    cout<<ans;

}