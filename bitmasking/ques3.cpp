#include <iostream>
using namespace std;
void countSetBits(int n){
    int count =0;
    while(n>0){
        if((n&1)==1){
            count ++;
        }
        n = n>>1;
    }
    cout<<count<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    countSetBits(n);
    return 0;
}