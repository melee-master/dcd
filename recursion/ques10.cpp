//Generate all possible combinations of paranthesis:
#include <iostream>
using namespace std;
void recursiveCall(int n, char *a, int open, int close, int pos){
    //Base Case:
    if(pos == 2*n){
        for(int j=0; j<pos; j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
        return;
    }

    //Recursive Case:
    if(open<n){
        a[pos] = '(';
        recursiveCall(n, a, open+1, close, pos+1);
    }
    if(close<open){
        a[pos]=')';
        recursiveCall(n, a, open, close+1, pos+1);
    }
}
int main(){
    char a[100];
    int n;
    cin>>n;
    recursiveCall(n, a, 0, 0, 0);
}