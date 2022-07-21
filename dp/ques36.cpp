#include <iostream>
#include <climits>
using namespace std;
int minJumps(int n, int *arr){
    int jumps[n];
    jumps[0]  = 0;
    for(int i=1; i<n; i++){
        jumps[i] = INT_MAX;
        for(int j=0; j<i; j++){
            if(i<=j+arr[j] && jumps[j]!=INT_MAX){
                jumps[i] = min(jumps[i], jumps[j]+ 1);
                break;
            }
        }
    }
    return jumps[n-1];
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin >> n;
        int arr[1005];
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        cout<<minJumps(n ,arr);
        t--;
    }
}