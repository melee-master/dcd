//Longest Common Subsequence :
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int LCS(string s1, string s2, int i, int j, vector<vector<int> >dp){
    //Base Case :
    if(i==s1.length() || j==s2.length()){
        return 0;
    }
    //Lookup:
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //Recursive Case :
    if(s1[i] == s2[j]){
        return dp[i][j] = 1  + LCS(s1, s2, i+1, j+1, dp);
    }
    int op1 = LCS(s1, s2, i, j+1, dp);
    int op2 = LCS(s1, s2, i+1, j, dp);
    return dp[i][j] = max(op1, op2);
}

int main(){
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int> > dp(n1, vector<int> (n2, -1)); //n1*n2 dp vector, each initialized with -1
    int ans = LCS(s1, s2, 0, 0, dp);


    cout<<ans;
}