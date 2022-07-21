//Join the ropes: 
#include <iostream>
#include <queue>
using namespace std;

int joinRopes(int ropes[], int n){
    priority_queue<int, vector<int> , greater<int> > pq(ropes, ropes+n);
    int cost = 0;
    while(pq.size()>1){
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        cost += (A+B);
        pq.push(A+B);
    }
    return cost;
}


int main(){
    int ropes[] = {4, 3, 2, 6};
    int n = sizeof(ropes)/sizeof(ropes[0]);
    cout<<joinRopes(ropes, n);

}