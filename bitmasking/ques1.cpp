//Set a particuar i bit with a partcular v value.
#include <iostream>
using namespace std;
void setBit(int &n, int v, int i){
    int mask = (1<<i);
    mask = ~mask;
    n = n & mask;
    n = n | (v<<i);
    return; 
}

int main(){
    int n, v, i;
    cin>>n>>v>>i;
    setBit(n, v, i);
    cout<<n;
    return 0;
}