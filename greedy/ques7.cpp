#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d;
    cin>>d;
    int l;
    vector<int>chopsticks;
    for(int i=0; i<n; i++){
        cin>>l;
        chopsticks.push_back(l);
    }
    sort(chopsticks.begin(), chopsticks.end());
    int count=0;
    int pairs=0;
    while(count<n){
        if(chopsticks[count+1]-chopsticks[count]<d){
            pairs++;
            count += 2;
        }else{
            count++;
        }
    }
    cout<<pairs;
}