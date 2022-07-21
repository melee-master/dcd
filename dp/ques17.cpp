//Matrix Chain multiplication:
#include <iostream>
using namespace std;
int matrixChainMultiplication(int *arr, int n){
    int dp[200][200];
    memset(dp, 0, sizeof (dp));
    n = n-1;
    for(int i=1; i<n; i++){
        int r =0 ;
        int c=i;
        while(c<n){
            int val = INT_MAX;
            for(int pivot = r; pivot<c; pivot++){
                val = min(val, dp[r][pivot] + dp[pivot+1][c] + (arr[r]* arr[pivot+1]* arr[c+1]) );
            }
            dp[r][c] = val;
            c++;
            r++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;

    }
    return dp[0][n-1];
}



int main(){
    int arr[] = {4, 2, 3, 1, 3};
    int n = sizeof (arr)/sizeof (int );

    cout<<matrixChainMultiplication(arr, n);
}






