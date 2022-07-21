#include <iostream>
using namespace std;
int recursiveCall(int start, int end, int *arr, int m){
    //Base case:
    if(arr[end]==m){
        return end;
    }
    if(end==start){
        return -1;
    }
    //Recursive Case:
    int pos = recursiveCall(start, end-1, arr, m);
    return pos;
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
    int pos = recursiveCall(0, n-1, arr, m);
    cout<<pos<<endl;
    return 0;
}
