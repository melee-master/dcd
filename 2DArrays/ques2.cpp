//Spiral Print: 
#include <iostream>
using namespace std;
void spiralPrint(int a[][100], int n, int m){
    int sr =0;
    int sc =0;
    int er =n-1;
    int ec =m-1;
    while(sr<=er and sc<=ec){
        for(int col=sc; col<=ec; col++){
            cout<<a[sr][sc]<<" ";
        }
        sr++;
        for(int row=sr; row<=er; row++){
            cout<<a[row][ec]<<" ";
        }
        ec--;
        if(sr<er){
            for(int col=ec; col>=sc; col--){
                cout<<a[er][col]<<" ";
            }
            er--;
        }

        if(sc<ec){
            for(int row=er; row>=sr; row--){
                cout<<a[row][sc]<<" ";
            }
            sc++;
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    int val=1;
    int arr[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j]=val;
            val++;
        }
    }

    spiralPrint(arr, n, m);

}