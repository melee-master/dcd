//fibonacci bottom up approach:
#include <iostream>
using namespace std;
int fibonacci(int n){
    int dp[100]={0};
    dp[1]= 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int ans = fibonacci(n);
    cout<<ans;

    return 0;
}
