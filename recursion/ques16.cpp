#include <iostream>
using namespace std;
int count(int n, int ld){
    //Base Case:
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
        return count(n-1, 0) + count(n-1, 1);
    }else{
        return count (n-1, 0);
    }


}
int main(){

    int n;
    cin>>n;
    int ans =count(n, 0);
    cout<<ans;
    return 0;
}