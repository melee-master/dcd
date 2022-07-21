#include <iostream>
using namespace std;
void piRemover(char *in, int i){
    if(in[i]=='\0' || in[i+1]=='\0'){
        cout<<in<<endl;
        return;
    }

    //Recursive Case:
    if(in[i]=='p' and in[i+1]=='i'){
        int j= i+1;
        while(in[j]!='\0'){
            j++;
        }
        while(j>=i+2){
            in[j+2] = in[j];
            j--;
        }
        in[i] ='3';
        in[i+1] = '.';
        in [i+2] = '1';
        in [i+3] = '4';
        piRemover(in, i+4);
    }else{
        piRemover(in, i+1);
    }
}
int main(){
    int n;
    cin>>n;
    while(n>0){
        char a[1000];
        cin>>a;
        piRemover(a, 0);
        n--;
    }
}
