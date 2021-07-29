#include <iostream>
#include <queue>
#include <map>
#include <list>
using namespace std;


template<typename T>
class Graph{
//    int V;
    map<T, list<T> > l ;
    
public:
    
  
    
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void bfs(T src)
    {
      map<T,int>visited;
      queue<T> q;
      q.push(src);
      visited[src] = true;
       
      while(!q.empty()){
          T node = q.front();
          q.pop();
          cout<<node;
          for(auto nbr: l[node]){
              if(!visited[nbr]){ 
                  q.push(nbr);
                  visited[nbr] = true;
              }
          }
      }
    }
    
    
    
    // void dfs_helper(T src, map<T,int> &visited){
    //     visited[src] = true;
    //     cout<<src;
        
    //     for(auto nbr : l[src]){
    //         if(!visited[nbr]){
    //             dfs_helper(nbr,visited);
    //         }
    //     }
    // }
    
    // void dfs(T src){
    //     map<T,int>visited;
        
    //     for(auto p :l){
    //         T node = p.first;
    //         visited[node] = false;
    //     }
    //     for(auto p:l){
    //     T nbr = p.first;
    //     if(!visited[nbr]){
    //         dfs_helper(nbr,visited);
    //     }    
    //     }
        
    // }
};


int main(int argc, const char * argv[]) {
    
    Graph<int> g;
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    
    g.bfs(1);
    
 
    return 0;
}
