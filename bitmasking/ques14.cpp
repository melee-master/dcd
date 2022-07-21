#include <iostream>
using namespace std;
int noOfSetBits(int n){
    int ans =0;
    while(n>0){
        if((n&1)!=0){
            ans++;
        }
        n = n>>1;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        cout<<noOfSetBits(n)<<endl;
        t--;
    }
    return 0;
}