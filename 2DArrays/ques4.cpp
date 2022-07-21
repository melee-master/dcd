#include <iostream>
using namespace std;

void stairCaseSearch(int arr[][4], int n, int m, int key){
    int i=0; 
    int j=m-1;
    while(i<n && j>=0){
        if(arr[i][j]==key){
            cout<<i<<" "<<j;
            break;
        }
        if(arr[i][j]<key){
            i++;
        }
        if(arr[i][j]>key){
            j--;
        }
    }
}
int main(){
    int a[4][4] = {
        {1, 4, 8, 10},
        {2, 5, 9, 15},
        {6, 13, 18, 20},
        {11, 14, 21, 25}
    };
    int n =4;
    int m=4;
    int key;
    cin>>key;
    stairCaseSearch(a, 4, 4, key);
    return 0;
}