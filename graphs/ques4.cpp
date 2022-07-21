//Single Source Shortest Path: 
#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template <typename T>
class Graph{
    map<T, list<T> >l;
    public:
    void addEdge(int x, int  y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src){
        map<T, int> dist;
        queue<T> q;
        for(auto nodePair : l){
            T node = nodePair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto nbr : l[node]){
                if(dist[nbr]==INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node]+1;
                }
            }
        }
        for(auto nodePair : l){
            T node = nodePair.first;
            int d = dist[node];
            cout<< node <<" " <<d <<endl;
        }
    }
};

int main(){
    Graph<int>g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);
    return 0;
}