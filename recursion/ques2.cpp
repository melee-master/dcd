//Take as input N, a number. Write a recursive function to find Nth triangle where 1st triangle is 1, 2nd triangle is 1 + 2 = 3, 3rd triangle is 1 + 2 + 3 = 6, so on and so forth. Print the value returned.

#include <iostream>
using namespace std;
int recursiveCall(int n, int end){
    //Base Case: 
    if(n==end){
        return n;
    }
    //Recursive Case:
    int sum = 0;
    sum = n + recursiveCall(n+1, end);     
    return sum;
}


int main(){
    int x = recursiveCall(0, 3);
    cout<<x;
    return 0;
}