//LIS-1(O(n^2))
#include <iostream>
using namespace std;

int LIS1(int arr[], int n){
    int dp[10] = {0};


     for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[j], dp[i]);
            }
        }
        dp[i]++;
    }
    return dp[n-1];
}


int main(){
    int arr[] = {1, 5, 2, 3, 4, 9, 6, 10};
    int n = sizeof (arr)/ sizeof (n);
    int ans = LIS1(arr, n);
    cout<<ans;
}