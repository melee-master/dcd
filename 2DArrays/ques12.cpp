#include <iostream>
using namespace std;
bool isPresent(int arr[30][30], int n, int m, int key){
    int i=0; 
    int j= m-1;
    while(i<n  && j>=0){
        if(arr[i][j]==key){
            return true;
            break;
        }
        if(arr[i][j]<key){
            i++;
        }
        if(arr[i][j]>key){
            j--;
        }
    }
    return false;
}
int main(){
    int n, m;
    cin>>n>>m;
    int arr[30][30];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;
    if(isPresent(arr, n, m, key)){
        cout<<1;
    }else{
        cout<<0;
    }

}