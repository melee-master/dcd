#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int>s;
    for(int i=n-1; i>=0; i--){
        s.push(i);
    }
    for(int i=0; i<n; i++){
        cout<<s.top()<<" ";
        s.pop();
    }

}