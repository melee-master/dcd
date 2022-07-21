//Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns an array containing indices of all items in the array which have value equal to M. Print all the values in the returned array.
#include<iostream>
using namespace std;
void recursiveCall(int start, int end, int *arr, int m, int count, int *arr2 ){
    //Base case:
    if(start>end){
        return;
    }
    if(arr[start]==m){
        arr2[count] = start;
        count++;
        recursiveCall(start+1, end, arr, m, count, arr2);
    }
    recursiveCall(start+1, end, arr, m, count, arr2);
    return ;
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
    
    int arr2[n];
    for(int i=0; i<n; i++){
        arr2[i] = 0;
    }

    recursiveCall(0, n-1, arr, m, 0, arr2);

    //count sort
    int arr3[n];
    for(int i=0; i<n; i++){
        arr3[i] = 0;
    }
    for(int i=0; i<n; i++){
        if(arr2[i]!=0){
            int pos = arr2[i];
            arr3[pos]++;
        }
    }


    
    for(int i=0; i<n; i++){
        if(arr3[i]!=0){
            cout<<i<<" ";
        }
    }
    return 0;

}
