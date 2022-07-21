#include <iostream>
#include <string>
#include <vector>
using namespace std;
int consecutiveForbid( int n, int ld){
    if(n==0){
        return 0;
    }
    if(n==1){
        if(ld==0){
            return 2;
        }else{
            return 1;
        }
    }

    //Recursive Case:
    if(ld==0){
        return consecutiveForbid(n-1, 0) + consecutiveForbid(n-1, 1);
    }else{
        return consecutiveForbid(n-1, 0);
    }
}



int main(){
    int n;
    cin>>n;
    int i=1;
    while(n>0){
        int a;
        cin >>a;
        int ans = consecutiveForbid(a, 0);
        cout<<"#"<<i<<" : "<<ans<<endl;
        i++;
        n--;
    }
}