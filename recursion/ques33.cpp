#include <iostream>
#include <string>
#include  <algorithm>
#include <vector>
#include <charconv>
using namespace std;
string word [] = {"","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
void recursiveCall(string in, string out, vector<string> &v){
    //base Case;
    if(in.length()==0){
        v.push_back(out);
        return;
    }
    //Recursive Case:

    string ch = in.substr(0, 1);
    recursiveCall(in.substr(1), out+word[stoi(ch)], v);
    if(stoi(in.substr(0, 2))>9 and stoi(in.substr(0, 2))<=26){
        recursiveCall(in.substr(2), out+word[stoi(in.substr(0, 2))], v);
    }
}
int main(){
    string a;
    cin>>a;
    string out="";
    vector<string>v;
    recursiveCall(a, out, v);
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}