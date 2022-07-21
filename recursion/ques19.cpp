#include <iostream>
using namespace std;
void recursiveCall(char *in, char *out, int i, int j){
    //Base Case:
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    //Recursive Case:
    recursiveCall(in, out, i+1, j);
    out[j] = in[i];
    recursiveCall(in, out, i+1, j+1);
}
int main(){
    char in[] = "abc";
    char out[10000];
    recursiveCall(in, out, 0, 0);
    return 0;
}