#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int>p1, pair<int, int>p2){
    return ((p1.second+p1.first) < (p2.second+p2.first));
}
int main(){
    int n;
    cin>>n;
    int c, r;
    vector<pair<int, int> >v;
    for(int i=0; i<n; i++){
        cin>>c>>r;
        v.push_back(make_pair(c, r));
    }
    int ans = 0;
    sort(v.begin(), v.end(), compare);
    int start = v[0].first + v[0].second;
    for(int i=1; i<n; i++){

        if(start>v[i].first-v[i].second){
            ans++;
        }else{
            start = v[i].first + v[i].second;
        }
    }
    cout<<ans;
    return 0;
}