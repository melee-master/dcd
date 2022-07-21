//LIS-3(O(nlogn))
//We have applied binary search
#include <iostream>
using namespace std;

int LIS1(int arr[], int n){
    int dp[n+1];
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }
    for(int i=0; i<n; i++){
        int length = upper_bound(dp, dp+n+1, arr[i])-dp;
        if(dp[length-1]<arr[i] && dp[length]>arr[i]){
            dp[length] = arr[i];
        }
    }
    int lis = 0;
    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
        if(dp[i]!=INT_MAX){

            lis=i;
        }
    }
    return lis;
}


int main(){
    int arr[] = {1, 5, 2, 3, 4, 9, 6, 10};
    int n = sizeof (arr)/ sizeof (n);
    int ans = LIS1(arr, n);
    cout<<ans;
}