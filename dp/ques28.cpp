#include <iostream>
using namespace std;
#define ull unsigned long long
ull dp[10000];
int uglyNumbers(int n){
    dp[0] = 1;
    int pointer2 = 0;
    int pointer3 = 0;
    int pointer5 = 0;
    for(int i=1; i<n; i++){

        dp[i] = min(dp[pointer2]*2, min(dp[pointer3]*3, dp[pointer5]*5));
        if(dp[i] == dp[pointer2]*2){
            pointer2++;
        }
        if(dp[i]==dp[pointer3]*3){
            pointer3++;
        }
        if(dp[i] == dp[pointer5]*5){
            pointer5++;
        }

    }

    return dp[n-1];
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        memset(dp, 0, sizeof (dp));
        ull ans = uglyNumbers(n);
        cout<<ans<<endl;
        t--;
    }
    return 0;
}