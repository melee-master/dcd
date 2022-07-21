#include <iostream>
using  namespace std;
int setBitCounter(int n){
    int ans =0;
    while(n>0){
        if((n&1)!=0){
            ans++;
        }
        n= n>>1;
    }
    return ans;
}
int counter(int a, int b){
    int ans =0;
    for(int i=a; i<=b; i++){
        ans += setBitCounter(i);
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
    int a, b;
    cin>>a>>b;
    cout<<counter(a, b)<<endl;
    t--;
    }
    return 0;
}