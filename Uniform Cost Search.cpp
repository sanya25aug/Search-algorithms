#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T,int> > > m;
    
public:
    void addEdge(T u,T v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist)); 
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
        
    }
    
    void printAdj(){
        //Let try to print the adj list
        //Iterate over all the key value pairs in the map 
        for(auto j:m){
            cout<<j.first<<"->";
            
            //Iterater over the list of cities
            for(auto l: j.second){
                    cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }
    }
    
    void uniform_cost_search(T src, T dest){
        unordered_map<T,int> dist;
        
        //Set all distance to infinity
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }
        
        //Make a set to find a out node with the minimum distance
        set<pair<int, T> > s; //set sorts according to the first parameter
        
        dist[src] = 0;
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            
            //Find the pair at the front.
            auto p =   *(s.begin());
            T node = p.second;
            
            int nodeDist = p.first;
            s.erase(s.begin());
            
            //Iterate over neighbours/children of the current node
            for(auto childPair: m[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    
                    //In the set updation of a particular is not possible
                    // we have to remove the old pair, and insert the new pair to simulation updation
                    T dest = childPair.first;
                    auto f = s.find( make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    
                    //Insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        
        //Lets print distance to all other node from src
        for(auto d:dist){
            if(d.first==dest)
            cout<<d.first<<" is located at a distance of "<<d.second<<" from "<<src<<endl;
        }
    }
};

int main(){
    Graph<string> India;
    India.addEdge("Delhi","Bangalore",100);
    India.addEdge("Delhi","Jaipur",400);
    India.addEdge("Jaipur","Bangalore",200);
    India.addEdge("Jaipur","Mumbai",800);
    India.addEdge("Bhopal","Agra",200);
    India.addEdge("Mumbai","Bhopal",300);
    India.addEdge("Agra","Bangalore",100);
    //india.printAdj();
    India.uniform_cost_search("Delhi", "Bhopal");

 return 0;
}
