//Cycle Detection in Directed Graph using Dfs: 
#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;
class graph{
    list <int> *l;
    int v;
    public: 
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
    }
    bool cycleHelper(int node, bool * visited, bool * stack){
        visited[node] = true;
        stack[node] = true;
        for(int nbr : l[node]){
            if(stack[nbr]==true){
                return true;
            }
            else if(visited[nbr]==false){
                bool nextCycle = cycleHelper(nbr, visited, stack);
                if(nextCycle==true){
                    return true;
                }
            }
        }
        stack[node] = false;
        return false;
    }
    bool cycleDetector(){
        bool * visited = new bool [v];
        bool * stack = new bool [v];
        for(int i=0; i<v; i++){
            stack[i] = visited[i] = false;
        }
        if(cycleHelper(0, visited, stack)){
            return true;
        }else{
            return false;
        }
        
    }
};
int main(){
    graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(0, 5);
    g.addEdge(4, 2);
    if(g.cycleDetector()){
        cout<<"CYCLE";
    }else{
        cout<<"NOT CYCLE";
    }
    return 0;
}
