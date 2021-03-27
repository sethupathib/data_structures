#include <bits/stdc++.h>
#include <map>
#include <list>
using namespace std;

template<typename T>

class Graph{
  map<T,list<T> > l; 
  public:


    void addEdge(int x, int y){
        l[x].push_back(y);
//         l[y].push_back(x);
    }  
    
    //dfs helper
    //pass visited array and ordering array by reference and not by value. 
    //It will another copy of the array if you do not pass by reference.
    void dfs_helper(int src, map<T,int>&visited, list<T> &ordering){
        
        visited[src] = true;
        
        for(auto nbr :l[src]){
           
            if(!visited[nbr]){
                dfs_helper(nbr,visited,ordering);
            }
        }
        ordering.push_front(src);
      return;
    }
    //dfs
    void dfs(){
        map<T,int>visited;
        list<T> ordering ;
        
        //make all nodes as not visited
        
        for(auto p:l){
            T node = p.first;
            visited[node] = false;
        }
        for(auto p:l){
            T nbr = p.first;
        
        if(!visited[nbr]){
            dfs_helper(nbr,visited,ordering);
            }
        }
        
        for(auto node: ordering){
            cout<<node;
        }
    }
    
    
};



int main(){
    
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.dfs();
    
    
    return 0;
}
