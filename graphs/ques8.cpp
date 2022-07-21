//DAG's Topological Sort: 
#include <iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;
template <typename T>
class Graph{
    map<T, list<T> >l;
    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
    }
    void dfsHelper(T src, map<T, bool> & visited, list < T > &order){
        visited[src]= true;
        for(T nbr : l[src]){
            if(!visited[nbr]){
                dfsHelper(nbr, visited, order);
            }
        }
        order.push_front(src);
        return ;
    }
    void dfs(T src){
        map<T, bool> visited;
        list <T> order;
        for(auto p : l){
            T node  = p.first;
            visited[node] = false;
        }
        for(auto p : l){
            T node = p.first;
            if(!visited[node]){
                dfsHelper(node, visited, order);
            }
        }
        for (auto node : order){
            cout<<node<<" ";
        }
    }
};
int main(){
    Graph<int>g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.dfs(0);
    return 0;
}
