//Recursively Reverse a stack: 
#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int>&s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    //Recusive Case :
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
    return;
}


void reverseStack(stack<int>&s){
    if(s.empty()){
        return ;
    }
    int x = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, x);
    
}
void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return;
}
int main(){
    stack<int> s1;
    for(int i=0; i<4; i++){
        s1.push(i);
    }
    printStack(s1);
    reverseStack(s1);
    printStack(s1);
    return 0;
}
