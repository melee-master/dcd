#include <iostream>
using namespace std;
void duplicateLetter(char *a, int i){
    //Base Case:
    if(a[i]=='\0' || a[i+1]=='\0'){
        return ;
    }

    //Recursive Case :
    if(a[i]==a[i+1]){
        int j = i+1;
        while(a[j]!='\0'){
            j++;
        }
        while(j>=i+1){
            a[j+1] = a[j];
            j--;
        }
        a[i+1]='*';
        duplicateLetter(a, i+3);
    }else{
        duplicateLetter(a, i+1);
    }
}
int main(){
    char a[1000];
    cin>>a;
    duplicateLetter(a, 0);
    cout<<a;

    return 0;
}