#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    vector<int> v;
    int sum =0;
    for(int i=0; i<n; i++){
        cin>>x;
        sum += x;
        v.push_back(x);
    }
    if(sum%n  != 0){
        cout<<-1<<endl;
    }else{
        int diff =0;
        int load = sum/n;
        int maxDiff =0;
        for(int i=0; i<n; i++){
            diff += v[i] - load;
            int ans = max(diff, -diff);
            maxDiff = max(ans, maxDiff);
        }
        cout<<maxDiff;
    }
    return 0;
}