#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[1000000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    stack<int>s;
    s.push(0);
    int arr2[n];
    arr2[0] = 1;
    for(int i=1; i<n; i++){
        int currentPrice = arr[i];
        while(!s.empty() and arr[s.top()]<currentPrice){
            s.pop();
        }
        if(s.empty()){
            arr2[i] = i+1;
        }else{
            int prevHighest = s.top();
            arr2[i] = i-prevHighest;
        }
        s.push(i);
    }
    for(int i=0; i<n; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<"END";
    
}