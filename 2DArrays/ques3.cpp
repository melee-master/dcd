#include <iostream>
using namespace std;
void printArray(int arr[][100], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotateImage(int arr[][100], int n, int m){
    //Transpose of a matrix: 
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i<j){
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    printArray(arr, n, m);
    cout<<endl;
    //Reverse The row:
    for(int row=0; row<n; row++){
        int x=0;
        int y=m-1;
        for(int col=0; col<m; col++){
            if(x<y){
                swap(arr[row][x], arr[row][y]);
                x++;
                y--;
            }
        }
    }
    printArray(arr, n, m);
}
int main(){
    int a[100][100]={0};
    int n;
    cin>>n;
    int val=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = val;
            val++;
        }
    }
    printArray(a, n, n);
    rotateImage(a, n, n);

}