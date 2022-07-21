//Cell Mitosis:
#include <iostream>
using namespace std;
int cellMitosis(int x, int y, int z, int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        if(i%2==0){
            dp[i] = min((dp[i-1] + y) , (dp[i/2] + x));
        }else{
            dp[i] = min((dp[(i+1)/2]+z+x), (dp[i-1]+y));
        }
    }
    return dp[n];
}



int main(){
    int n;
    cin>>n;
    int arr[3];
    for(int i=0; i<3; i++){
        cin>>arr[i];
    }
    cout<< cellMitosis(arr[0], arr[1], arr[2], n);


    return 0;
}
