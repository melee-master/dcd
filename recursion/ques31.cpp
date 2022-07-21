#include <iostream>
using namespace std;
void recursiveShifter(char *in, int i){
    //Base Case:
    if(in[i]=='\0'){
        cout<<in;
        return;
    }


    //Recursive Case:
    if(in[i]=='x'){
        int j=i+1;
        while(in[j]!='\0'){
            in[j-1] = in[j];
            j++;
        }
        in[j-1] = 'x';
        recursiveShifter(in, i+1);
    }else{
        recursiveShifter(in, i+1);
    }

}




int main(){
    char in[1000];
    cin>>in;
    recursiveShifter(in, 0);

    return 0;
}