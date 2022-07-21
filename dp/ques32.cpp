#include <iostream>
using namespace std;
int dp[1005][1005];
long long consecutiveOne(int ld, int n, int dp[1005][1005]){
    //Base Case:
    if(n==0){
        return 0;
    }
    if(n==1){
        if(ld==0){
            return 2;
        }else{
            return 1;
        }
    }
    if(dp[ld][n]!=-1){
        return dp[ld][n];
    }

    //Recursive Case:
    long long ans  =0;
    if(ld==0){
        ans = consecutiveOne(0, n-1, dp) + consecutiveOne(1, n-1, dp);
        return dp[ld][n] = ans;
    }
    ans = consecutiveOne(0, n-1, dp);
    return dp[ld][n] = ans;

}




int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        memset(dp, -1, sizeof (dp));
        cout<< consecutiveOne(0, n, dp)<<endl;
        t--;
    }
}