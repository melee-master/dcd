#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int>&s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
    return;
}

void reverseRecursively(stack<int>&s){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverseRecursively(s);
    insertAtBottom(s, x);
}
int main(){
    int n;
    cin>>n;
    stack <int> s;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        s.push(x);
    }
    reverseRecursively(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}