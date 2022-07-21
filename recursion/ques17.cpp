#include <iostream>
using namespace std;
int recursiveCall(int n){
    //Base Case:
    if(n==0 || n==1){
        return 1;
    }


    //Recursive Case :
    int ans = recursiveCall(n-1) + (n-1)* recursiveCall(n-2);
    return ans;

}
int main(){

    int n;
    cin>>n;
    int ans = recursiveCall(n);
    cout<<ans;

    return 0;
}