//Depth First Search: 
#include <iostream>
#include <queue>
#include <map>
#include <list>
using namespace std;
template <typename T>
class graph{
    map <T, list<T> >l;
    public: 
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void DFSHelper(T src, map<T, bool> & visited){
        //Recursive function that will traverse the Graph :
        cout<<src<<" ";
        visited[src] = true;
        for(T nbr : l[src]){
            if(!visited[nbr]){
                DFSHelper(nbr, visited);
            }
        }
        return ;
    }
    void DFS(T src){
        map<T, bool> visited;
        for(auto nodePair : l){
            T node = nodePair.first;
            visited[node] = false;
            cout<<endl;
        }
        DFSHelper(src, visited);
    }
};
int main(){
    graph <int> G;
    G.addEdge(0, 1);
    G.addEdge(0, 3);
    G.addEdge(3, 2);
    G.addEdge(1, 2);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(7,8);
    G.addEdge(8, 9);
    G.addEdge(9, 7);
    G.DFS(0);

    
    return 0;
}