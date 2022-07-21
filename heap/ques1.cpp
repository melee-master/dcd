//Insertion in Heap: 
#include <iostream>
#include <vector>
using namespace std;
class heap{
    vector <int> v;
    bool minHeap;
    bool compare(int a, int b){
        if(minHeap==true){
            return a<b;
        }else{
            return a>b;
        }
    }
    void heapify(int index){
        int left = 2 * index;
        int right = 2*index + 1;

        int minIndex = index;
        int lastIndex = v.size()-1;
        if(left<=lastIndex && compare (v[left], v[index])){
            minIndex = left;
        }
        if(right<=lastIndex && compare(v[right], v[minIndex])){
            minIndex = right;
        }
        if(minIndex!= index){
            swap(v[minIndex], v[index]);
            heapify(minIndex);
        }
        return ;
    }
    public: 
    heap(int defaultSize  =10, bool type = true){
        v.reserve(defaultSize);
        v.push_back(-1);
        minHeap = type;
    }
    //Adding element in the Heap: 
    void push(int d){
        v.push_back(d);
        int index = v.size()-1;
        int parent  =index/2;
        while(index>1 and compare(v[index], v[parent])){
            swap(v[index], v[parent]);
            index = parent;
            parent = index/2;
        }
    }
    int top(){
        return v[1];
    }
    //Popping element ftom the array: 
    bool empty(){
        if(v.size()==1){
            return true;
        }
        return false;
    }
    void pop(){
        int last = v.size()-1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }
};
int main(){
    heap h;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int no;
        cin>>no;
        h.push(no);
    }
    while(!h.empty()){
        int topElement = h.top();
        cout<<topElement<<" ";
        h.pop();
    }
    return 0;
}
