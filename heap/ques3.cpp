//Array to heap - optimized approach:
#include <iostream>
#include <vector>
using namespace std;
bool compare(int a, int b){
    return a>b;
}
void heapify(int index, vector<int> &v){
    int leftIndex = 2 *index;
    int rightIndex = 2*index +1;
    int minIndex = index;
    int lastIndex = v.size() - 1;
    
    if(leftIndex<=lastIndex && compare(v[leftIndex], v[index])){
        minIndex = leftIndex;
    }
    if(rightIndex<=lastIndex && compare(v[rightIndex], v[minIndex])){
        minIndex = rightIndex;
    }
    if(minIndex!=index){
        swap(v[minIndex], v[index]);
        heapify(minIndex, v);
    }
    return;
}

void buildHeapOptimised(vector <int> &v){
    for(int i = (v.size()-1)/2; i>=1; i--){
        heapify(i, v );
    }
}
int main(){
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    buildHeapOptimised(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}