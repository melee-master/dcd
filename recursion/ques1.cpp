//lexicographically print from 1 to n numbers;


#include<iostream>
using namespace std;
void lexico(int start, int end){
    //Base Case:
    if(start> end){
        return ;
    }
    if(start==end){
        cout<<start<<endl;
        return ;
    }
    if(start!=0){
        cout<<start<<" ";
    }
    //Recursive Case:
    for(int i= (start==0)? 1 : 0; i<=9; i++){
         lexico((start*10)+i, end);
    }
}
int main(){
    lexico(0, 13);
}


