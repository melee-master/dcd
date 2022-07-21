#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int p =1;
    int n;
    cin>>n;
    string s;

    while(n>0){
        if(n%2==0){
            s.push_back('0');
        }else{
            s.push_back('1');
        }
        n= n/2;
    }
    reverse(s.begin(), s.end());
    cout<<s;
    
}