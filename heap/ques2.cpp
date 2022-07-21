//Converting an array / vector to a heap : (in place i.e. cannot use another heap object).
#include <iostream>
#include <vector>
using namespace std;

void buldHeap(vector<int> & v){
    for(int i = 2; i<v.size(); i++){
        int index = i;
        int parent = index/2;
        while(index > 1 && v[index] > v[parent]){
            swap(v[parent], v[index]);
            index = parent;
            parent = parent / 2;
        }
    }
}
int main(){
    vector <int> v {-1, 10, 20, 5, 6, 1, 8, 9, 4}; 
    buldHeap(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

}