#include <iostream>
#include <vector>
using namespace std;
int main(){

    int gridRow;
    int gridCol, towerCount;
    vector<int>xTower;
    vector<int>yTower;
    cin>>gridRow;
    cin>>gridCol;
    cin>>towerCount;
    int x, y;
    for(int i=0; i<towerCount; i++){
        cin>>x>>y;
        xTower.push_back(x);
        yTower.push_back(y);
    }
    sort(xTower.begin(), xTower.end());
    sort(yTower.begin(), yTower.end());
    int dx = xTower[0]-1;
    int dy = yTower[0]-1;
    for(int i=1; i<towerCount; i++){
        dx = max(dx, xTower[i]-xTower[i-1]-1);
        dy = max(dy, yTower[i]-yTower[i-1]-1);
    }
    dx = max(dx, x-xTower[towerCount-1]);
    dy = max(dy, y-yTower[towerCount-1]);
    cout<<dx*dy;
    return 0;
}