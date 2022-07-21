//Indian Coin change problem:
#include <iostream>
#include <algorithm>

using namespace std;
void make_change(int n, int *change, int money){
    int ans = 0;
    while(money>0){
        int indx = upper_bound(change, change+n, money)-change-1;
        cout<<change[indx]<<" ";
        money -= change[indx];
        ans++;
    }
    cout<<ans;
}

int main(){
    int change []= {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof (change)/sizeof (int);
    int money;
    cin>>money;
    make_change(n, change, money);
    return 0;
}



