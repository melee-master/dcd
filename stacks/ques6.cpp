#include <iostream>
#include <stack> 
using namespace std; 

// Function to print Next Greater Element for each element of the array
void nextGreater(int arr[], int n) 
{ 
    stack<int> s;
    s.push(0);
    int arr2[100000];
    for(int i=1; i<n; i++){
        int nextElement = arr[i];
        if(s.empty()){
            s.push(i);
            continue;
        }
        while(!s.empty() && nextElement>arr[s.top()]){            
            arr2[s.top()] = nextElement;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        arr2[s.top()] = -1;
        s.pop();
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<","<<arr2[i]<<endl;
    }

} 

// The Main Function
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        nextGreater(arr, n); 
    }
	
	return 0; 
} 

