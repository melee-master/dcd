#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int ans =0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        ans = ans^arr[i];
    }
    int pos =0;
    while(ans>0){
        if((ans&1)!=0){
            break;
        }
        pos++;
        ans = ans>>1;
    }
    int unique1 =0;
    int unique2 =0;
    int mask = 1<<pos;
    for(int i=0; i<n; i++){
        if((arr[i]&mask)>0){
            unique1 = unique1 ^ arr[i];
        }else{
            unique2 = unique2 ^ arr[i];
        }
    }
    if(unique1<unique2){
        cout<<unique1<<' '<<unique2;
    }else{
        cout<<unique2<<" "<<unique1;
    }
    return 0;
}