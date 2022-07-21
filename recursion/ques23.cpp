#include <iostream>
#include <string>
#include  <algorithm>
#include <vector>
#include <charconv>
using namespace std;
string word [] = {"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
void recursiveCall(string a, string b, vector<string> &v){
    //Base Case:
    if(a.length() == 0){
        v.push_back( b);
        return;
    }

    //Recursive Case:
    string ch = a.substr(0, 1);

    recursiveCall(a.substr(1), b+word[stoi(ch)], v);
    if(stoi(a.substr(0, 2))>=10 && stoi(a.substr(0, 2))<=26){
        recursiveCall(a.substr(2), b+word[stoi(a.substr(0, 2))], v);
    }


}
int main(){
    int n;
    string b="";
    cin>>n;
    string a = to_string(n);
    vector<string>v;
    recursiveCall(a, b, v);
    sort(v.begin(), v.end());
    cout<<"[";
    for(int i=0; i<v.size(); i++){
        if(i<v.size()-1) {
            cout << v[i] << ", ";
        }else{
            cout<<v[i];
        }

    }
    cout<<"]";

    return 0;
}