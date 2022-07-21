//Largest area in a histogram: 
#include <iostream>
#include <stack>
using namespace std;
void largestArea(int *arr, int n){
    stack<long long int>s;
    long long int area = 0;
    s.push(0);
    for(int i=1; i<=n; i++){
        if(s.empty()){
            s.push(i);
        }else{
            while(!s.empty() and arr[s.top()]>arr[i]){
                long long int top = s.top();
                s.pop();
                if(s.empty()){
                    area = max(area, arr[top]*i);
                }else{
                    area = max(area, (arr[top]* (i-s.top()- 1)));
                }
            }
            s.push(i);
        }
        
    }
    while(!s.empty()){
        long long int area =0;
        long long int x = s.top();
        s.pop();
        if(s.empty()){
            area = max(area, arr[x]*n);
        }else{
            area = max(area, arr[x]*(n-x));
        }
    }
    cout<<area;
}
int main(){
    int arr[10005];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    arr[n] = 0;
    largestArea(arr, n);
    
}