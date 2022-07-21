//Ladders Top-Down approach:
#include <iostream>
using namespace std;

int ladders(int n, int dp[], int k){
    //Base Case :
    if(n==0){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    //Recursive Case:
    int ways = 0;
    for(int i=1; i<=k; i++){
        if(n-i>=0){
            ways += ladders(n-i, dp, k);
        }
    }
    return dp[n] = ways;

}
int main(){
    int n;
    int k;
    cin>>n>>k;

    int dp[10] = {0};
    int ans =ladders(n, dp, k);
    cout<<ans;


}