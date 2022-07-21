#include <iostream>
#include <string>
using namespace std;
int recursiveCall(int n, char *a){
    //Base Case:
    if(n==0){
        return 0;
    }
    //Recursive Case :
    int digit = a[n-1]-'0';
    int bigAns = recursiveCall(n-1, a);
    int ans = bigAns*10 + digit;
    return ans;
}


int main(){
    char a[1000];
    cin>>a;
    int number = recursiveCall(strlen(a), a);
    cout<<number;
    return 0;
}