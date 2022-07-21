//Subset sum to target:
#include <iostream>
using namespace std;
bool sumChecker(int a[], int n, int s, bool dp[1000][1000]){
    if(s==0){
        return true;
    }
    if(n<=0){
        return false;
    }
    if(a[n-1]<=s){
        return dp[n][s] = sumChecker(a, n-1, s, dp) || sumChecker(a, n-1, s-a[n-1], dp);
    }
    return dp[n][s] = sumChecker(a, n-1, s, dp);
}


int main(){
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bool dp[1000][1000];
    bool isTrue = sumChecker(arr, n, sum, dp);
    if(isTrue){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}