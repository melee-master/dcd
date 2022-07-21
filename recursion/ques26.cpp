#include <iostream>
#include <cmath>
using namespace std;
void towerOfHanoi(char src[2], char dest[2], char helper[2], int n){
    if(n==0){

        return;
    }
    //Recursive Case:

    towerOfHanoi(src, helper, dest, n-1);

    cout<<"Move "<<n<<"th disc from "<<src<<" to "<<dest<<endl;

    towerOfHanoi(helper, dest, src, n-1);
}

int main(){
    int n;
    cin >> n;

    char a[] = "T1";
    char b[] = "T2";
    char c[] = "T3";
    towerOfHanoi(a, b, c, n);
    cout<<pow(2, n)-1;
}