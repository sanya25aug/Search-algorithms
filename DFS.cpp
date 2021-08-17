#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>>adjlist;

    public:
    void addEdge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void print(){
        //iterate over the map
        for(auto i: adjlist){
            cout<<i.first<<"->";

            //i.second is LL
            for(T entry:i.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }

    void dfsHelper(T node, map<T, bool> &visited){
        
        //whenever come to a node, mark it visited
        visited[node]=true;
        cout<<node<<" ";

        //try to find out a node which is neighbour of current node and not yet visited
        for(T neighbour: adjlist[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
        }
    }

    void dfs(T src){
        map<T, bool> visited;
        dfsHelper(src, visited);
    }
};

int main()
{
    Graph<int> g;
    int V, E;
    cout<<"Enter number of vertices: ";
    cin >> V;
    cout<<"Enter number of edges: ";
    cin >> E;
    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Enter edge "<<i<<" :";
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int src;
    cout<<"Enter source node: ";
    cin>>src;
    cout<<"DFS: ";
    g.dfs(src);
    return 0;
}