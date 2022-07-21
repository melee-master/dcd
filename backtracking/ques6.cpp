#include <iostream>
#include<cmath>
using namespace std;
bool canPlace(int mat[][1000], int i, int j, int n, int number){
    //For checking Row and Column:
    for(int k=0; k<n; k++){
        if(mat[i][k]==number || mat[k][j]==number){
            return false;
        }
    }
    //For checking the subgrid:
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int q=sx; q<sx+rn; q++){
        for(int w=sy; w<sy+rn; w++){
            if(mat[q][w] == number){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int mat[][1000], int i, int j, int n){
    //Base Case:
    if(i==n){
        for(int q=0; q<n; q++){
            for(int w=0; w<n; w++){
                cout<<mat[q][w]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //Recursive Case:
    if(j==n){
        return sudokuSolver(mat, i+1, 0, n);
    }
    if(mat[i][j]!=0){
        return sudokuSolver(mat, i, j+1, n);
    }
    for(int number = 1; number <=n; number++){
        if(canPlace(mat, i, j, n ,number)){
            mat[i][j] = number;
            if(sudokuSolver(mat, i, j+1, n)){
                return true;
            }
        }
    }
    mat[i][j]=0;
    return false;
}

int main(){
    int mat[1000][1000]={0};
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }
    if(!sudokuSolver(mat, 0, 0, n)){
        cout<<"FAIL";
    }
    return 0;
}