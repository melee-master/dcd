//Friends Pairing problem:
#include <iostream>
using namespace std;
int friendsPairing(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    int ans = friendsPairing(n-1) + (n-1) *friendsPairing(n-2);
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<friendsPairing(n);
}
