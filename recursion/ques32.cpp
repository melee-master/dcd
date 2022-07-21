#include <iostream>
#include <string>
using namespace std;
int converter(string in, int n){
    //Base Case :
    if(n==0){
        return 0;
    }

    //Recursive Case:

    int ans = converter(in, n-1) * 10 + (in[n-1]-'0');
    return ans;

}
int main(){
    string a;
    cin>>a;
    int n=a.length();
    int ans = converter(a, n);

   cout<<ans;

}