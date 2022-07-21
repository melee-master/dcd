#include <iostream>
using namespace std;
void clearBits(int &n, int i, int j){
    int ma = (~0);
    ma = (ma<<j);
    int mb = (1<<i)-1;
    int m = (ma | mb);
    n= (n & m);

}
void updateBits(int &n, int m, int i, int j){
    m = m<<(i-1);
    clearBits(n, i-1, j);
    n = n|m;

}
int main(){
    int n;
    cin>>n;
    updateBits(n, 2, 2, 4);
    cout<<n;
}