#include <iostream>
using namespace std;
int recursiveCall(int n){
    //Base Case:
    if(n<=3){
        return 1;
    }
    //Recursive case :
    int ans = recursiveCall(n-1) + recursiveCall(n-4);
    return ans;
}
int main(){
    int n;
    cin>>n;
    int ans = recursiveCall(n);
    cout<<ans;
}