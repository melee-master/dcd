#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void recursiveCall(string  n, vector<string>& v){
    if(stoi(n)<0){
        return;
    }
    int digit = stoi(n);
    if(digit>=0){
        v.push_back(n);
        digit--;
        n = to_string(digit);
        recursiveCall(n, v);
    }
}
int main(){
    int n;
    cin>>n;
    string a = to_string(n);
    vector<string>v;
    recursiveCall(a, v);
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }


    return 0;
}