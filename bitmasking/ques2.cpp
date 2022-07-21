//Check wether the give number is odd or even and also check wether a particukar bits is 0 or 1;

#include <iostream>
using namespace std;
void check(int n, int i){
    if((n&1)==1){
        cout<<"ODD"<<endl;
    }else{
        cout<<"EVEN"<<endl;
    }

    if((n& (1<<i))>0){
        cout<<i<<"th bit is 1";
    }else{
        cout<<i<<"th bit is 0";
    }
    return ;
}

int main(){
    int n;
    cin>>n;
    int i;
    cin>>i;
    check(n, i);
}