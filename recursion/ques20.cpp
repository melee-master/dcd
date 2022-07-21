#include <iostream>
using namespace std;
void towerOfHanoi(char src, char dest, char helper, int n){
    //Base Case :
    if(n==0){
        return ;
    }
    //Recursive Case:

    //Step1: n-1 disk from src to helper:
    towerOfHanoi(src, helper, dest, n-1);
    cout<<"move "<< n << " disk from "<<src <<" to"<< dest<<endl;
    towerOfHanoi(helper, dest, src, n-1);
}


int main(){
    towerOfHanoi('A', 'B', 'C', 3);
}