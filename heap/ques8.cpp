//Median in a running stream of integers: 
#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int> > rightHeap;
    int data;
    cin>>data;
    float median = data;
    leftHeap.push(data);
    cin>>data;
    while(data!=-1){
        if(leftHeap.size() > rightHeap.size()){
            if(data<median){
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(data);
            }else{
                rightHeap.push(data);
            }
            median = (leftHeap.top() + rightHeap.top())/2;
        }else if(leftHeap.size() == rightHeap.size()){
            if(data<median){
                leftHeap.push(data);
                median = leftHeap.top();
            }else{
                rightHeap.push(data);
                median = rightHeap.top();
            }
        }else{
            if(data>median){
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(data);
            }else{
                leftHeap.push(data);
            }
            median = (leftHeap.top() + rightHeap.top())/2;
        }
        cin>>data;
    }
    cout<<median;
    return 0;
}