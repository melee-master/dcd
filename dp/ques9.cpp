//Maximum Sub array Sum space optimization :
#include <iostream>
using namespace std;
int maxSumOptimized(int arr[], int n){
    int currentSum = 0;
    int maxSum =0;
    for(int i=0; i<n; i++){
        currentSum += arr[i];
        if(currentSum<0){
            currentSum =0;
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
int main(){
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof (arr) / sizeof (int);
    int ans = maxSumOptimized(arr, n);
    cout<<ans;
    return 0;
}