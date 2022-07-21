//Minimum Cost Path:
#include <iostream>
using namespace std;
int minimumCostPath(int r, int c, int cost[4][4]){
    int dp[100][100] = {0};
    for(int i=0 ;i<r; i++){
        for(int j=0; j<c; j++){
            if(i==0 && j==0){
                dp[i][j] = cost[i][j];
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1] + cost[i][j];
            }
            else if(j==0){
                dp[i][j] = dp[i-1][j] + cost[i][j];
            }else{
                int op1 = dp[i-1][j] +  cost[i][j];
                int op2 = dp[i][j-1] + cost[i][j];
                dp[i][j] = min(op1, op2);
            }
        }
    }
    return dp[r-1][c-1];
}




int main(){
    int arr [4][4]= {{9,4,9,9},
                    {6,7,6,4},
                    {8,3,3,7},
                    {7,4,9,10}};
    int rows = sizeof(arr)/sizeof(arr[0]);
    int columns = sizeof (arr[0])/sizeof (int);
    cout<<minimumCostPath(rows, columns, arr);

}