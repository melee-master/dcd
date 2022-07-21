#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair <int, int> p1, pair <int, int> p2){
    return p1.second < p2.second;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int s, e;
        vector<pair<int, int> >st;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>s>>e;
            st.push_back(make_pair(s, e));
        }
        sort(st.begin(), st.end(), compare);
        int prevEnd = st[0].second;
        int count =1;
        for(int i=1; i<n; i++) {
            if (st[i].first >= prevEnd) {
                prevEnd = st[i].second;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}