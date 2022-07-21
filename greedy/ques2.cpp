//Busy Man SPOJ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second< p2.second;
}
int main(){
    vector<pair<int, int>> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int s, e;
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }
    sort(v.begin(), v.end(), compare);
    int count = 1;
    int end = v [0].second;

    for(int i=1; i<n; i++){
        if(end<=v[i].first){
            end = v[i].second;
            count++;
        }
    }
    cout<<count;
    v.clear();
}