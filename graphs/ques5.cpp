//BFS sssp problem: SNAKE AND LADDERS
#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template <typename T>

class Graph{
    map<T, list<T> >l;
    public: 
    void addEdge(int x, int y){
        l[x].push_back(y);
    }
    void bfs(T src, T dest){
        map<T, int> dist;
        queue<T> q;
        for(auto nodePair : l){
            T node = nodePair.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto nbr : l[node]){
                if(dist[nbr]==INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] +1;
                }
            }
        }
        int d = dist[dest];
        cout<<d;
    }
};
int main(){
    //Input: 

    //board: 
    int board[50] = {0};
    //Snakes and Ladders: 
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //Add edges to the graph: 
    Graph<int> g;
    for(int i=0; i<37; i++){
        for(int dice = 1; dice<=6; dice++){
            int j = i+dice;
            j += board[j];
            if(j<=36){
                g.addEdge(i ,j);
            }
        }
    }
    g.addEdge(36, 36);
    g.bfs(0, 36);

    

}
