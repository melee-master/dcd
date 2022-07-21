#include <iostream>
#include <string>
#include <vector>
using namespace std;
void generator(string input, string output, vector<int> &v){
    if(input.length() == 0){
        cout<<output<<" ";
        v[0]++;
        return;
    }

    //ignore ith character:
    generator(input.substr(1), output, v);
    generator(input.substr(1), output+input.substr(0, 1), v);
}


int main(){
    vector<int>v;
    v.push_back(0);
    generator("abcd", "", v);
    cout<<"\n"<<v[0];


}