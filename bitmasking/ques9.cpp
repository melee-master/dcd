#include <iostream>
using namespace std;
int main(){
    int a[] = {3, 3, 3, 6, 6, 6, 5};
    int n = sizeof (a)/sizeof (int);
    int cnt[64] = {0};
    for(int i=0; i<n; i++){
        int pos = 0;
        int temp = a[i];
        while(temp > 0){
            if((temp&1)==1){
                cnt[pos]++;
            }
            pos++;
            temp = temp >> 1;
        }
    }

    for(int i=0; i<64; i++){
        cnt[i] = cnt[i]%3;
    }
    int ans =0;
    int p =1;
    for(int i=0; i<64; i++){
        ans += p*cnt[i];
        p = p<<1;
    }
    cout<<ans;
}