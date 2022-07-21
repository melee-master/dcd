//Reverse a stack using 1 stack:
#include <iostream>
#include <stack>
using namespace std;
void transferBetweenStacks(stack<int>&s1, stack<int>&s2, int n){
    for(int i=0; i<n; i++){
        s2.push(s1.top());
        s1.pop();
    }
    return;
}
void reverseStack(stack<int>&s1){
    stack<int>s2;
    int n=s1.size();
    for(int i=0; i<n; i++){
        //Store the top element :
        int x = s1.top();
        s1.pop();
        //Transfer n-1-i elements from s1 to s2;
        transferBetweenStacks(s1, s2, n-i-1);
        //Put element x in s1: 
        s1.push(x);
        //Transfer elements from S2 to s1: 
        transferBetweenStacks(s2, s1, n-i-1);
    }
    return;
}
void printStack(stack<int>s1){
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    return;
}
int main(){
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    printStack(s1);
    reverseStack(s1);
    printStack(s1);
    return 0;
}