#include <iostream>
using namespace std;
int bitonicSubsequence(int arr[], int n){
    int lis[n];
    lis[0] =1;
    for(int i=1; i<n; i++){
        lis[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1){
                lis[i] = lis[j]+1;
            }
        }
        
    }
    
    
    int lds[n];
    for(int i=0; i<n; i++){
        lds[i] = 1;
    }
    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i]>arr[j] && lds[i]<lds[j]+1){
                lds[i] = lds[j]+1;
            }
        }
    }
    
    int bitonic[n];
    for(int i=0; i<n; i++){
        bitonic[i] = lis[i]+ lds[i] -1;
    }
    int ans =bitonic[0];
    for(int i=1; i<n; i++){
        ans = max(ans, bitonic[i]);
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<bitonicSubsequence(arr, n)<<endl;
        t--;
    }
}