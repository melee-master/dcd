#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int arr[10][10];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int sr=0;
    int sc=0;
    int er=n-1;
    int ec=m-1;
    while(er>=sr && ec>=sc){
        for(int i=sr; i<=er; i++){
            cout<<arr[i][sc]<<", ";
        }
        sc++;
        for(int i=sc; i<=ec; i++){
            cout<<arr[er][i]<<", ";
        }
        er--;
        if(sc<=ec){
            for(int i=er; i>=sr; i--){
                cout<<arr[i][ec]<<", ";
            }
            ec--;
        }
        if(sr<=er){
            for(int i=ec; i>=sc; i--){
                cout<<arr[sr][i]<<", ";
            }
            sr++;
        }
        
    }
    cout<<"END";
    return 0;
}