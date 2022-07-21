//Take as input N, a number. Print the following pattern (for N =4)
//*
//* *
//* * *
//* * * *
//* * * * *


#include <iostream>
using namespace std;
void recursiveCall(int start, int end){
    if(start>end){
        return;
    }
    for(int i=0; i<start; i++){
        cout<<"*\t";
    }
    cout<<endl;
    recursiveCall(start+1, end);
    return ;
}

int main(){
    int n;
    cin>>n;
    recursiveCall(0, n);
    return 0;
}