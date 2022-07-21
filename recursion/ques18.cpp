#include <iostream>
using namespace std;
void recursiveCall(int o, int c, int n, char*a, int pos){
    //Base Case:
    if(pos==2*n){
        a[pos]='\0';
        cout<<a<<endl;
        return;
    }
    //Recursive case :
    if(o<n){
        a[pos] = '(';
        recursiveCall(o+1, c, n, a, pos+1);
    }
    if(c<o){
        a[pos]=')';
        recursiveCall(o, c+1, n, a, pos+1);
    }
}


int main(){

    int n;
    cin>>n;
    char a[1000];
    recursiveCall(0, 0, n, a, 0);

    return 0;
}