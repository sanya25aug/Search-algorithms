#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> adjlist;

public:
    void addEdge(T u, T v, bool bidirectionalEdge = true)
    {
        adjlist[u].push_back(v);
        if (bidirectionalEdge)
        {
            adjlist[v].push_back(u);
        }
    }

    void printAdjlist()
    {

        //iterate over the map
        for (auto i : adjlist)
        {
            cout << i.first << "->";

            for (T entry : i.second)
            {
                cout << entry << ",";
            }
            cout << endl;
        }
    }

    void bfs(T src)
    {
        queue<T> q;
        map<T, bool> visited;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();

            // For the neighbours of current node find nodes that are not visited
            for (int neighbour : adjlist[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
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
    cout<<"BFS: ";
    g.bfs(src);

    return 0;
}