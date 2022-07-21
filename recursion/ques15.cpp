#include <iostream>
using namespace std;
int stairs(int n, int k){
    //Base Case:
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    //Recursive Case:
    int ans =0;
    for(int i=1; i<=k; i++){
        ans += stairs(n-i, k);
    }
    return ans;

}
int main(){
    int n, k;
    cin>>n>>k;
    int ans = stairs(n ,k);
    cout<<ans;
    return 0;
}