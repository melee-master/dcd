//Rat and Elephant ways:
#include <iostream>
using namespace std;

int elephantWays(int dp[10][10], int r, int c){

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i==0 && j==0){
                dp[i][j] = 1;
            }
            else{
                int part1 = 0;
                int part2 = 0;
                for(int x=0; x<=i-1; x++){
                    part1 += dp[x][j];
                }
                for(int y=0; y<=j-1; y++){
                    part2 += dp[i][y];
                }
                dp[i][j] = part1 + part2;
            }
        }
    }

    return dp[r-1][c-1];

}
int main(){
    int dp[10][10] = {0};
    cout<< elephantWays(dp ,3, 5);
}