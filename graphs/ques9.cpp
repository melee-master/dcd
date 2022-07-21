//Topological sort using BFS: 
#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;
class Graph{
    list <int > * l;
    int v;
    public: 
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
    }
    void topologicalSort(){
        int * indegree = new int[v];
        for(int i=0; i<v; i++){
            indegree[i] = 0;
        }
        for(int i =0; i<v; i++){
            for(auto nbr : l[i]){
                indegree[nbr]++;
            }
        } 
        //BFS: 
        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //Start removing elements form the queue: 
        while(!q.empty()){
            int top = q.front();
            cout<<top<<" ";
            q.pop();
            for(auto nbr: l[top]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
};
int main(){

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(2, 5);
    g.topologicalSort();
    return 0;
}
