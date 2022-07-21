#include <iostream>
using namespace std;
void generateParanthesis(char *a, int n, int o, int c, int i){
    if(i==2*n){
        a[i] = '\0';
        cout<<a<<endl;
        return;
    }
    if(o>c){
        a[i] = ')';
        generateParanthesis(a, n, o, c+1, i+1);
    }
    if(o<n){
        a[i] = '(';
        generateParanthesis(a, n, o+1, c, i+1);
    }

}
int main(){
    int n;
    cin>>n;
    char a[100];
    generateParanthesis(a, n, 0, 0, 0);
}