//Catalan Number:
#include <iostream>
using namespace std;
int dp[100] = {0};
int catalanNumber(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans =0;
    for(int j=1; j<=n; j++) {
        ans += catalanNumber(j - 1) * catalanNumber(n - j);
        dp[n] = ans;
    }
    return dp[n];
}



int main(){

    int n;
    cin>>n;
    cout<<catalanNumber(n);
    return 0;
}