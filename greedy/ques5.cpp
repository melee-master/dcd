#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[10000];
    int sum =0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum +=arr[i];
    }
    int load  = sum/n;
    int diff =0;
    int max_load =0;
    for(int i=0; i<n; i++){
        diff += arr[i] - load;
        int ans = max(diff, -diff);
        max_load = max(ans, max_load);
    }
    cout<<max_load;
}