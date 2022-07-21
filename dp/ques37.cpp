#include <iostream>
#include <climits>
using namespace std;
int dp[1005][1005][10];
int LCS(int *arr1, int *arr2, int n1, int n2, int k){
    //Base Case :
    if(n1<0 || n2<0){
        return 0;
    }
    if(dp[n1][n2][k]!=-1){
        return dp[n1][n2][k];
    }
    int res = 0;
    if(arr1[n1] == arr2[n2]){
        res = 1 + LCS(arr1, arr2, n1-1, n2-1, k);
    }else{
        if(k>0){
            res = 1  +LCS(arr1, arr2, n1-1, n2-1, k-1);
        }
        res = max(res, max(LCS(arr1, arr2, n1-1, n2, k), LCS(arr1, arr2, n1, n2-1, k)));
    }
    return dp[n1][n2][k] = res;
}



int main(){
    int n1, n2;
    int k;
    cin>>n1>>n2>>k;
    int arr1[n1];
    int arr2[n2];
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }
    memset(dp, -1, sizeof dp);
    cout<<LCS(arr1, arr2, n1, n2, k);
}