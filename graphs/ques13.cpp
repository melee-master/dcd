//Dijkstras: 
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class Graph{
    unordered_map<T, list<pair<T, int> > > m;
    public: 
    
    void addEdge(T u, T v, int dist, bool bidir = true){
        m[u].push_back(make_pair(v, dist));
        if(bidir==true){
            m[v].push_back(make_pair(u, dist));
        }
    }

    void printAdjList(){
        for(auto j : m){
            cout<<j.first<<"->";
            for(auto l : j.second){
                cout<<l.first<<"at a distance"<<l.second<<endl;
            }
            cout<<"**********"<<endl;
        }
    }

    void dijkstra(T src){
        unordered_map<T, int> dist;
        for(auto j : m){
            dist[j.first] = INT_MAX;
        }
        set <pair <int, T > > s;
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while(!s.empty()){
            //Find min pair: 
            auto p = *(s.begin());
            T node = p.second;
            int nodeDistance = p.first;
            s.erase();
            //Iterate over neighbours of the current node: 
            for(auto childPair : m[node]){
                if(nodeDistance + childPair.second < dist[childPair.first]){
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest] = nodeDistance + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
    }

};
int main(){
    Graph<string> g;
    g.addEdge("Agra", "Delhi", 5);
    g.printAdjList();
}