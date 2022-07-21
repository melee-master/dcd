#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int>s;
    while(n>0){
        int decider;
        cin>>decider;
        
        if(decider==2){
            int price;
            cin>>price;
            s.push(price);
        }
        if(decider==1){
            if(!s.empty()){
                cout<<s.top()<<endl;
                s.pop();
            }else{
                cout<<"No Code"<<endl;
            }
        }
    n--;
    }
}