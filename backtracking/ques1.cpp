#include <iostream>
using namespace std;
bool isSafe(int arr[10][10], int row, int col, int n){
    //column check: 
    for(int i=row-1; i>=0; i--){
        if(arr[i][col] == 1){
            return false;
        }
    }
    int x = row;
    int y = col;
    //Left diagonal
    while(x>=0 && y>=0){
        if(arr[x][y]== 1){
            return false;
        }
        x--;
        y--;
    }
    x = row;
    y = col;
    //Right diagonal:
    while(x>=0 && y<=n-1){
        if(arr[x][y]== 1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool solveNQueen(int arr[10][10], int i, int n, int *arr2){
    //Base Case:
    if(i==n){
        
        for(int y=0; y<n; y++){
            for(int u=0; u<n; u++){
                if(arr[y][u]==1){
                    cout<<"{"<<y<<"-"<<u<<"}"<<" ";
                }
            }
        }
        cout<<"  ";
        arr2[0]++;
    }


    //Recursive Case:
    for(int j=0; j<n; j++){
        if(isSafe(arr, i, j, n)){
            arr[i][j]=1;
            bool nextQueen = solveNQueen(arr, i+1, n, arr2);
            if(nextQueen){
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}





int main(){
    int n;
    cin>>n;
    int arr[10][10] = {0};
    int arr2[2] = {0};
    solveNQueen(arr, 0, n, arr2);
    cout<<"\n"<<arr2[0];
    return 0;
}