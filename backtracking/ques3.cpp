#include <iostream>
using namespace std;
bool cheeseChaser(char maze[1000][1000], int sol[1000][1000], int n, int m, int i, int j){
    //Base Case :
    if(i==n-1 and j==m-1){
        sol[i][j]=1;
        return true;
    }
    //Recursive Case :
    if(i>=n || j>=m) {
        return false;
    }

    if(maze[i][j] == 'X'){
        return false;
    }
    if(sol[i][j] == 1){
        return false;
    }
    sol[i][j] = 1;
    //Right Case:
    if(j<m-1){
        bool right = cheeseChaser(maze, sol, n, m, i, j+1);
        if(right){
            return true;
        }
    }
    //Left Case:
    if(j>0){
        bool left = cheeseChaser(maze, sol, n, m, i, j-1);
        if(left){
            return true;
        }
    }
    //up case:
    if(i>0){
        bool up = cheeseChaser(maze, sol, n, m, i-1, j);
        if(up){
            return true;
        }
    }
    //Down Case :
    if(i<n-1){
        bool down = cheeseChaser(maze, sol, n, m, i+1, j);
        if(down){
            return true;
        }
    }
    sol[i][j] = 0;
    return false;
}
int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    char maze[1000][1000];
    int sol[1000][1000] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
        }
    }

    if(cheeseChaser(maze, sol, n, m, 0, 0)){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<-1;
    }
}