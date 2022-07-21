//optimal game strategy:
#include <iostream>
using namespace std;
int recursiveCall(int i, int j, int dp[100][100], int *a){
    //Base case:
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }


    //Recursive Case:
    int op1 = a[i]+ min(recursiveCall(i+2, j, dp, a), recursiveCall(i+1, j-1, dp,a));
    int op2 = a[j]+ min(recursiveCall(i+1, j-1, dp, a), recursiveCall(i, j-2, dp, a));
    dp[i][j] = max(op1, op2);
    return dp[i][j];
}




int main(){
    int dp[100][100] = {0};
    int arr[] = {8, 15, 3, 7};
    int n  = sizeof (arr)/ sizeof (int);
    cout<<recursiveCall(0, n-1, dp, arr);
}