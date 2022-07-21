//2 unique numbers:
#include <iostream>
using namespace std;
int main(){
    int arr[] = {6, 5, 1, 6, 1, 3};
    int n = sizeof(arr)/sizeof(int);
    int ans=0;
    for(int i=0; i<n; i++){
        ans  = ans ^ arr[i];
    }
    int pos =0;
    while(ans>0){
        if((ans&1)>0){
            break;
        }
        pos++;    
        ans = ans >>1;
    }
    int mask =(1<<pos);
    int op1=0;
    int op2=0;
    for(int i=0; i<n; i++){
        if((arr[i]&mask)==0){
            op1 = op1^arr[i];
        }else{
            op2 = op2^arr[i];
        }
    }
    cout<<"unique numbers are: "<<op1<<" and"<<op2;
    return 0;
}