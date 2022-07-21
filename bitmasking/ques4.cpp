#include <iostream>
using namespace std;
void clearBitRange(int &n, int j, int i){
    int ma = (~0);
    ma = (ma<j);
    int mb = (1<<i)-1;
    int m = (ma | mb);
    n = (n&m);
}
int main(){
    int n;
    cin>>n;
    clearBitRange(n ,4, 2);
    cout<<n;
}