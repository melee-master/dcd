//Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns the first index at which M is found in the array and -1 if M is not found anywhere. Print the value returned.

#include <iostream>
using namespace std;
int recursiveCall(int start, int end, int *arr, int m){
    //Base case:
    if(arr[start]==m){
        return start;
    }
    if(start==end){
        return -1;
    }
    int position = recursiveCall(start+1, end, arr, m);
    return position;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int position  = recursiveCall(0, n-1, arr, m);
    cout<<position;
    return 0;
}