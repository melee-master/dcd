//Heap Sort(In place sorting algorithm): 
#include <iostream>
#include <vector>
using namespace std;
bool compare(int a, int b){
    return a>b;
}
void printVector(vector<int>v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}
void heapify(vector<int> &v, int index, int size){
    int leftIndex = 2 * index;
    int rightIndex = 2 * index  +1;
    int minIndex  = index;
    int lastIndex = size-1;
    if(leftIndex<=lastIndex && compare(v[leftIndex], v[index])){
        minIndex = leftIndex;
    }
    if(rightIndex<=lastIndex && compare(v[rightIndex], v[minIndex])){
        minIndex = rightIndex;
    }
    if(index!=minIndex){
        swap(v[index], v[minIndex]);
        heapify(v, minIndex,  size);
    }
    return ;
}
void buildHeap(vector<int> &v){
    for(int i=(v.size()-1)/2; i>=1 ; i--){
        heapify(v, i, (v.size()-1));
    }
}


void heapSort(vector<int> &v){
    buildHeap(v);
    int n = v.size();
    while(n>1){
        swap(v[1], v[n-1]);
        n--;
        heapify(v, 1,  n);
    }
}



int main(){
    vector<int> v {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    heapSort(v);
    printVector(v);
}