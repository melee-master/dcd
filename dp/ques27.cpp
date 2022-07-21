#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[5005][5005];
ll a[5005];
ll b[5005];
ll n, m;
ll f(ll i, ll j){
    //Base Case :
    if(i==n){
        return 0;
    }

    if(j==m){
        return 10000000;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //Recursive Case :

    int op1 = abs(a[i]- b[j]) + f(i+1, j+1);
    int op2 = f(i, j+1);
    return dp[i][j] = min(op1, op2);
}
int main(){

    cin>>n>>m;

    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    for(ll i=0; i<m; i++){
        cin>>b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    memset(dp, -1, sizeof (dp));
    cout<<f(0, 0);

}