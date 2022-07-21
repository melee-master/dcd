//Wave Print
#include <iostream>
using namespace std;
int main(){
    int a[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for(int col=0; col<4; col++){
        if(col%2==0){
            for(int j=0; j<4; j++){
                cout<<a[j][col]<<" ";
            }
            
        }else{
            for(int j=3; j>=0; j--){
                cout<<a[j][col]<<" ";
            }
            
        }
    }

}