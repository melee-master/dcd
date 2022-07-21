//Connecting Wires:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> whitePos;
    vector<int> blackPos;
    for(int i=0; i<n/2; i++){
        int pos;
        cin>>pos;
        whitePos.push_back(pos);
    }
    for(int i=0; i<n/2; i++){
        int pos;
        cin>>pos;
        blackPos.push_back(pos);
    }
    sort(whitePos.begin(), whitePos.end());
    sort(blackPos.begin(), blackPos.end());
    int sum =0;
    for(int i=0; i<n/2; i++){
        if(whitePos[i]-blackPos[i]<0){
            sum += blackPos[i]-whitePos[i];
        }else{
            sum += whitePos[i]-blackPos[i];
        }
    }

    cout<<sum;

}