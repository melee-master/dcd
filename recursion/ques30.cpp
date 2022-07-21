#include <iostream>
#include <string>
using namespace std;
string keys[] = {" ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void stringGenerator(char* input, char* output, int i, int *a){
    //Base Case:
    if(input[i]=='\0'){
        output[i] = '\0';
        cout<<output<<" ";
        a[0]++;
        return;
    }
    //Recursive Case:
    int digit = input[i] - '0';
    for(int k=0; keys[digit][k]!='\0'; k++){
        output[i] = keys[digit][k];
        stringGenerator(input, output, i+1, a);
    }
}
int main(){
    char output[100];
    char input[100];
    cin>>input;
    int a[1]={0};
    stringGenerator(input, output, 0, a);
    cout<<"\n"<<a[0];
    return 0;
}
