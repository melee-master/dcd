//Check if The undirected graph is a tree or not: 
#include <iostream>
#include <list>
#include <map>
#include <queue>
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
        l[y].push_back(x);
    }
    bool isTree(){
        bool *visited = new bool[v];
        int *parent = new int[v];
        queue<int>q;
        for(int i=0; i<v; i++){
            parent[i]=i;
        }
        q.push(0);
        visited[0] = true;
        //Pop out one node and visit it's neighbour: 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr : l[node]){
                if(visited[nbr]==true and parent[node]!=nbr){
                    return false;
                }
                else if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]= node;
                }
            }
        }
        return true;
    }
};
int main(){
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    if(g.isTree()){
        cout<<"TREE";
    }else{
        cout<<"NOT TREE";
    }
    
}