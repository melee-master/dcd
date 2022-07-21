//Generate combination of 2 character strings from a 2digit of a keypad

#include <iostream>
using namespace std;
string keys[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void stringGenerator(char *input, char *output, int i){
    //Base Case;
    if(input[i]=='\0'){
        output[i]='\0';
        cout<<output<<endl;
        return;
    }
    //Recursive Case:
    int digit = input[i] - '0';
    for(int k=0; keys[digit][k]!='\0'; k++){
        output[i] = keys[digit][k];
        stringGenerator(input, output, i+1);
    }
}

int main(){
    char output[100];
    char input[100];
    cin>>input;
    stringGenerator(input, output, 0);

}