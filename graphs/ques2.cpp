#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;
class graph{
    unordered_map <string,  list<pair<string, int> > > l;
    public: 
    void addEdge(string x, string y, bool isDirected, int wt){
        l[x].push_back(make_pair(y, wt));
        if(!isDirected){
            l[y].push_back(make_pair(x, wt));
        }
    }
    void printGraph(){
        for(auto p : l){
            string city = p.first;
            list <pair<string, int> >nbrs = p.second;
            for(auto nbr : nbrs){
                cout << nbr.first << ": " << p.second << endl;
            }
            cout<<"****************"<<endl;
        }
    }

};
int main(){
    graph g;
    g.addEdge("A","B", false, 20);
    g.addEdge("A","C", false, 10);
    g.addEdge("A","D", true, 50);
    g.addEdge("B","D", false, 40);
    g.addEdge("C","D", false, 30);
    g.printGraph();
    return 0;
}