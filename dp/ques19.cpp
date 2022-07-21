//Mixtures-SPOJ;
#include <iostream>
using namespace std;
int a[1000];
int dp[1000][1000];
int sum(int c, int b){
    int sum = 0;
    for(int i=c; i<=b; i++){
        sum+=a[i];
        sum = sum%100;
    }
    return sum;
}
int solveMixtures(int s, int e){
    if(s>=e){
        return 0;
    }
    if(dp[s][e] != -1){
        return dp[s][e];
    }
    dp[s][e] = INT_MAX;
    for(int k=s; k<=e; k++) {
        dp[s][e] = min(dp[s][e], solveMixtures(s, k)+ solveMixtures(k+1, e)+ sum(s, k) * sum(k+1, e));
    }
    return dp[s][e];
}

int main(){
    int n;
     cin>>n;
     for(int i=0; i<n; i++){
         cin>>a[i];
     }
     for(int i=0; i<=n; i++){
         for(int j=0; j<=n; j++){
             dp[i][j] = -1;
         }
     }
     cout<<solveMixtures(0, n-1);

}