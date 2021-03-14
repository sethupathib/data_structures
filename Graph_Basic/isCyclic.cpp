#include<bits/stdc++.h>
#include <list>
#include <algorithm>
#include <map>

using namespace std;
// template<typename T>

class Graph {
    int V;
 list<int> *l;
   public:
   Graph(int V){
       this->V = V;
       l = new list<int>[V];
   }
   
  
  void addEdge(int x, int y){
      l[x].push_back(y);
      l[y].push_back(x);
  }
  
  bool cycle_helper(int node, bool * visited, int parent){
      visited[node] = true;
      
      for(auto nbr: l[node]){
          //two cases
          if(!visited[nbr]){
              //recursively visit the neighbours
              //this line is to detect cycle if it is not present in the current component
              bool cycle_mila = cycle_helper(nbr,visited,node);
              if(cycle_mila){
                  return true;
              }
          }
          //nbr is visited and it is not the parent
          else if (nbr!=parent){
              return true;
          }
      }
  }


  bool containsCycle(){
      bool *visited = new bool[V];
      for(int i =0;i<V;i++){
          visited[i] = false;
      }
      
      return cycle_helper(0,visited,-1 );
      //cycle_helper(current_node, visited array, parent);
  }
  
  };


int main(){
    
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    if(g.containsCycle()){
    cout<<"Cycle present in the given graph";
        
    }
    else
    cout<<"Cycle not present";
    

    
    return 0;
}
