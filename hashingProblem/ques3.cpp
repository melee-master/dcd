//longest subarray with sum k;
#include <iostream>
#include <unordered_map>
using namespace std;
int longestSubarrayWithSumK(int arr[], int n, int k){
    unordered_map<int, int> m;
    int pre =0 ;
    int len =0;
    for(int i=0; i<n; i++){
        pre += arr[i];
        if(pre==k){
            len = max(len, i+1);
        }
        if(m.find(pre-k)!=m.end()){
            len = max(len, i-m[pre]);
        }else{
            m[pre] = i;
        }
    }
    return len;
}




int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<longestSubarrayWithSumK(arr, n, k);
    return 0;
}