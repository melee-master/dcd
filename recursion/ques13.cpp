#include <iostream>
using namespace std;
void recursiveCall(char *a, int i){
    //Base Case:
    if(a[i] == '\0' || a[i+1] =='\0'){
        return;
    }

    //Recursive Case:
    if(a[i]=='p' and a[i+1]=='i'){
        int j=i+2;
        while(a[j]!='\0'){
            j++;
        }
        while(j>=i+2){
            a[j+2] = a[j];
            j--;
        }
        a[i] ='3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';
        recursiveCall(a, i+4);
    }else{
        recursiveCall(a, i+1);
    }
}
int main(){
    char a[1000];
    cin>>a;

    recursiveCall(a, 0);
    cout<< a;
    return 0;
}