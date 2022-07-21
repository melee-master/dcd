#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> v1, pair<int, int> v2){
    return v1.first > v2.first;
}

int main(){
    int n, D, F;
    cin>>n;
    vector<pair<int, int> >v;
    priority_queue<int> pq;
    int d, f;
    for(int i=0; i<n; i++){
        cin>>d>>f;
        v.push_back(make_pair(d, f));
    }
    sort(v.begin(), v.end(), compare);
    cin>>D>>F;
    for(int i=0; i<n; i++){
        v[i].first = D-v[i].first;
    }
    int flag =0;
    int ans=0;
    int prev =0;
    int x=0;
    while(x<n){
        if(F>=(v[x].first-prev)){
            F = F-(v[x].first-prev);
            pq.push(v[x].second);
            prev = v[x].first;
        } else{
            if(pq.empty()){
                flag =1;
                break;
            }
            F += pq.top();
            pq.pop();
            ans = ans + 1;
            continue;
        }
        x++;
    }
    if(flag==1){
        cout<<-1;
    }else {
        D = D - v[n - 1].first;
        if (F >= D) {
            cout << ans << endl;
        } else {
            while (F < D) {
                if (pq.empty()) {
                    flag = 1;
                    break;
                }
                F += pq.top();
                pq.pop();
                ans++;
            }
            if (flag == 1) {
                cout << -1 << endl;

            }else {
                cout << ans << endl;
            }
        }
    }
}