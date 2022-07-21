//Disjoint set union DS:
//Union
//Find
//Cycle Detection in undirected graph using DSU: 
#include <iostream>
#include <list>
using namespace std;
class graph{
    int v;
    list<pair <int, int> >l;
    public: 
    graph(int v){
        this->v = v;
    }
    void addEdge(int u, int v){
        l.push_back(make_pair(u, v));
    }
    int findSet(int i, int parent[]){
        if(parent[i]==-1){
            return i;
        }
        //Finds Leader of the set: 
        //Path compression optimiztion: 
        return parent[i] = findSet(parent[i], parent);
    }
    
    void unionSet(int x, int y, int parent[], int rank[]){
        int s1 = findSet(x, parent, rank);
        int s2 = findSet(y, parent, rank);
        if(s1!=s2){
            if(rank[s1]>rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }else{
                parent[s2] = s1;
                rank[s1] += rank[s2]; 
            }
        }
        
    }

    bool containsCycle(){
        //DSU logic to check wether graph contains cycle or not: 
        int * parent = new int[v];
        int * rank = new int[v];

        for(int i=0; i<v; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
        //Iterate over edge list: 
        for(auto edge : l){
            int i = edge.first;
            int j = edge.second;
            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);
            if(s1!=s2){
                unionSet(s1, s2, parent);
            }else{
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};

int main(){
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
   
    if(g.containsCycle()){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
 