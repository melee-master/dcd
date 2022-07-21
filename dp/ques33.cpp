#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dp[1000][1000];
string v="";
int LCS(string a, string b, int i, int j){
    if(a.length()==i){
        return 0;
    }
    if(b.length()==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(a[i] == b[j]){
        char ch = a[i];
        v += ch;
        return dp[i][j] = LCS(a, b, i+1, j+1)+ 1;
    }
    int op1 = LCS(a, b, i+1, j);
    int op2 = LCS(a, b, i, j+1);
    return dp[i][j] = max(op1, op2);
}

int main(){
    string a, b;
    cin>>a;
    cin>>b;
    int i =0;
    int j =0;
    memset(dp, -1, sizeof dp);
    int ans = LCS(a, b, 0, 0);
    cout<<v;
}