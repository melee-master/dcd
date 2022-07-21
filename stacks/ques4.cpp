//Stock Span Problem: 
#include <iostream>
#include <stack>
using namespace std;
void stockSpan(int prices[], int n, int span[]){
    stack<int>s;
    s.push(0);
    span[0] = 1;
    for(int i=1; i<n; i++){
        int currentPrice = prices[i];
        while(!s.empty() and prices[s.top()]<currentPrice){
            s.pop();
        }
        if(!s.empty()){
            int prevHighest = s.top();
            span[i] = i-prevHighest;
        }else{
            span[i] = i+1;
        }
        s.push(i);
    }
}
int main(){
    int arr[] = {100, 80, 60, 70, 60, 75, 80};
    int n = sizeof(arr)/sizeof(int);
    int span[1000]={0};
    stockSpan(arr, n, span);
    for(int i=0; i<n; i++){
        cout<<span[i]<<" ";
    }
    return 0;
}