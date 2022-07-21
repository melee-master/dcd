//priority queue STL: 
#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> q;
    priority_queue<int, vector<int> , greater<int> > minH;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int no;
        cin>>no;
        q.push(no);
        minH.push(no);
    }
    while(!q.empty()){
        int no = q.top();
        cout<<no<<" ";
        q.pop();
    }
    cout<<endl;
    while(!minH.empty()){
        int no = minH.top();
        cout<<no<<" ";
        minH.pop();
    }
    


    return 0;
}