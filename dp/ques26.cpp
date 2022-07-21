//Minimum Money needed (oranges)

#include <iostream>
#include <climits>
using namespace std;
int orangeWeight(int *arr, int w){
    int dp[1000];
    dp[0] = 0;
    for(int i=1; i<=w; i++){
        int minCost = INT_MAX;
        for(int j=0; j<w; j++){
            if(j+1<=i && arr[j]!=-1){
                minCost = min(minCost, dp[i-j-1]+arr[j]);
            }
        }
        dp[i] = minCost;
    }
    return dp[w];
}

int main(){
    int N, W;
    cin>>N>>W;
    int arr[1000];
    for(int i=0; i<W; i++){
        cin>>arr[i];
    }
    cout<<orangeWeight(arr, W);

}