#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans =0;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        ans = ans^num;
    }
    cout<<ans;
    return 0;
}