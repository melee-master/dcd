//Maximum subarray sum:
#include <iostream>
using namespace std;
int maximumSum(int a[], int n){
    int dp[100] = {0};
    dp[0] = a[0]>0?a[0]: 0;
    int maxSoFar = dp[0];
    for(int i=1; i<n; i++){
        dp[i]  = dp[i-1] + a[i];
        if(dp[i]<0){
            dp[i] = 0;
        }
        maxSoFar = max(maxSoFar, dp[i]);
    }
    return maxSoFar;
}
int main(){
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof (arr) / sizeof (int);
    int ans = maximumSum(arr, n);
    cout<<ans;
    return 0;
}
