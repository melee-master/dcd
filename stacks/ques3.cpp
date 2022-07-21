#include <iostream>
#include <stack>
using namespace std;
bool paranthesisChecker(char *s){
    stack<char>s1;
    for(int i=0; s[i]!='\0'; s++){
        char ch = s[i];
        if(ch=='('){
            s1.push(ch);
        }
        else if(ch==')'){
            if(!s1.empty()){
                s1.pop();
            }else{
                return false;
            }
        }else{
            continue;
        }
    }
    if(s1.empty()){
        return true;
    }
    return false;
}
int main(){
    char ch[100] = ")((a+b)+c(d+e))";
    bool isCorrect = paranthesisChecker(ch);
    if(isCorrect){
        cout<<"TRUE";
    }else{
        cout<<"FALSE";
    }
    return 0;
}