#include <iostream>
#include <stack>
using namespace std;
bool paranthesisChecker(char *s){
    stack <char> a;
    for(int i=0; s[i]!='\0'; i++){
        char ch= s[i];
        if(ch=='('){
            a.push(ch);
        }else{
            if(!a.empty()){
                a.pop();
            }else{
                return false;
            }
        }
    }
    if(a.empty()){
        return true;
    }else{
        return false;
    }

}
int main(){
    char s[100000];
    cin>>s;
    bool balanced = paranthesisChecker(s);
    if(balanced){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

}