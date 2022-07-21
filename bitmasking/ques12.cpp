#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int cnt[64]={0};
    for(int i=0; i<n; i++){
        int temp = arr[i];
        int pos =0;
        while(temp>0){
            if((temp&1)!=0){
                cnt[pos] ++;
            }
            pos++;
            temp= temp>>1;
        }
    }
    for(int i=0; i<64; i++){
        cnt[i] = cnt[i]%3;
    }
    int p = 1;
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans +cnt[i]*p;
        p = p<<1;
    }
    cout<<ans;
    return 0;
}