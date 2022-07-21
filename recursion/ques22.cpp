#include <iostream>
#include <string>
#include  <algorithm>
#include <vector>

using namespace std;
void recursiveCall(string a, string b, int i, vector<string> &v){
    //Base case :
    if(i == a.length()){
        v.push_back(b);
        return ;
    }
    //add the letter:
    char ch = a[i];
    recursiveCall(a, b+ch, i+1,  v);
    recursiveCall(a, b, i+1, v);
    recursiveCall(a, b+ to_string(toascii(ch)), i+1, v);
}



int main(){
    string a;
    string b ="";
    cin>>a;
    vector<string> v;
    recursiveCall(a, b, 0, v);
    cout<<" ";
    for(int i=0; i<v.size(); i++){
        if (v[i] != "")
        {
            cout << v[i] << " ";
        }
    }
    cout<<endl;
    cout<<v.size();
    return 0;
}