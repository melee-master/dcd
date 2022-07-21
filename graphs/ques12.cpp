//Cycle Detection in graph using DFS: 
#include <iostream>
#include <list>
#include <map>
using namespace std;
class graph{
    int v;
    list <int> *l;
    public: 
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool cycleHelper(int node, int parent, bool * visited){
        visited[node] = true;
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                bool cyclePresent = cycleHelper(nbr, node, visited);
                if(cyclePresent){
                    return true;
                }
            }
            else if(nbr!=parent){
                return true;
            }
        }
        return false;
    }
    bool containsCycle(){
        bool * visited = new bool[v];
        for(int i=0; i<v; i++){
            visited[i] = false;
        }
        if(cycleHelper(0, -1, visited)){
            return true;
        }
        return false;
    }
};
int main(){
    graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 4);
    g.addEdge(4, 3);
    g.addEdge(3, 2);
    g.addEdge(2, 1);
    if(g.containsCycle()){
        cout<<"CYCLE";
    }else{
        cout<<"NO CYCLE";
    }
    
}