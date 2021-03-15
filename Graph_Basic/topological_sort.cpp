#include<bits/stdc++.h>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
class Graph {
    map<T, list<T> > l;
    public:
    
    void addEdge (int x, int y,bool bidir){
        l[x].push_back(y);
        if(bidir){
            l[y].push_back(x);
        }
    }
    
    //dfs_helper
    
    void dfs_helper(T node, map<T,bool> &visited, list<T> ordering){
        
        visited[node] = true;
        for(auto p:l){
         T node = p.first;   
        
        
        if(!visited[node]){
            visited[node] = true;
            dfs_helper(node,visited, ordering);
        }
    }
    ordering.push_front(node);
    return;
    
    //dfs
    
    void dfs(){
        
        map<T,bool> visited;
        
        for(auto p:l){
            T node = p.first;
          visited[node] = false;
        }
        
        for(auto p:l){
            
            T node = p.first
            if(!visited[node]){
                
                dfs_helper(node,visited)
            }
        }
        
        for(auto node : ordering){
            cout<<node<<endl;
        }
    }
    
    
    
};





int main(){
    
    Graph g;
    
    g.addEdge(1,2,false);
    g.addEdge(1,3,false);
    g.addEdge(2,4,false);
    g.addEdge(3,4,false);
    
    
    
    
    return 0;
}
