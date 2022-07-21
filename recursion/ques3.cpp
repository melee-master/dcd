//Take as input N, the size of array. Take N more inputs and store that in an array. Write a recursive function which returns true if the array is sorted and false otherwise. Print the value returned.
#include <iostream>
using namespace std;
bool recursiveCall(int start, int end, int *arr){
    if(start==end){
        return true;
    }
    if(arr[start]>arr[start+1] && recursiveCall(start+1, end, arr)){
        return true;
    }
    return false;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int arr2[n];
    for(int i=0; i<n; i++){
        arr2[i]= arr[n-i-1];
    }
    if(recursiveCall(0, n-1, arr) or recursiveCall(0, n-1, arr2)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}
