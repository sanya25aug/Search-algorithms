#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
using namespace std;

template <typename T>
class Graph{
    // map to store the graph as adjacency list
    // key-> node, value-> list of nodes connected to the key(node)
    map<T, list<T>> adjList;

public:
    // add edge will add the edge from one node to another
    // by default bidirectional edge is true, can be changed to false in case of directed graph
    void addEdge(T u, T v, bool bidirectionalEdge = true)
    {
        adjList[u].push_back(v);
        if (bidirectionalEdge)
        {
            adjList[v].push_back(u);
        }
    }

    // function to print the adjaceny list for each node
    void printAdjlist()
    {

        //iterate over the map
        for (auto i : adjList)
        {
            cout << i.first << "->";

            for (T entry : i.second)
            {
                cout << entry << ",";
            }
            cout << endl;
        }
    }

    // bfs function
    void bfs(T src, T dest) {
        queue<T> q;
		map<T,int> dist;
		map<T,T> parent;

		for(auto i:adjList){
			dist[i.first] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty()){

			T node = q.front();
			cout<<node<<" ";
			q.pop();

			// For the neigbours of the current node, find out the nodes which are not visited
			for(int neigbour :adjList[node]){
				if(dist[neigbour]==INT_MAX){
					q.push(neigbour);
					dist[neigbour] = dist[node]  + 1;
					parent[neigbour] = node;
				}
			}
		}
        cout<<endl;

		//Print the distance of destination node from source node
		for(auto i:adjList){
		        if(i.first==dest){
				T node = i.first;
				cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
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
    int src, dest;
    cout<<"Enter source node: ";
    cin>>src;
    cout<<"Enter destination node: ";
    cin>>dest;
    cout<<"BFS traversal: ";
    g.bfs(src, dest);

    return 0;
}
