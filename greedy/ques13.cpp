#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dx;
    vector<int> dy;
    int x, y;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        dx.push_back(x);
        dy.push_back(y);
    }
    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    int maxDx =0;
    int maxDy =0;
    for(int i=1; i<n; i++){
        maxDx = max(maxDx, dx[i]-dx[i-1]-1);
        maxDy = max(maxDy, dy[i]-dy[i-1]-1);
    }
    cout<<maxDx*maxDy;

    return 0;
}