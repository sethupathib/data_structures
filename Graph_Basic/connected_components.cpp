#include<bits/stdc++.h>
#include <list>
#include <algorithm>
#include <map>

using namespace std;
template<typename T>

class Graph {
    
  map<T,list<T> > l;
   public:
  
  void addEdge(int x, int y){
      l[x].push_back(y);
      l[y].push_back(x);
  }
  
//   void breadthFS(T src){
//       queue<T> q;
     
//       map<T,int > dist;
      
//       for(auto node_pair:l){
//           T node = node_pair.first;
//           dist[node] = INT_MAX;
//       }
//       q.push(src);
//       dist[src]=0;
      
//       while(!q.empty()){
//           T node = q.front();
//           q.pop();
//         //   cout<<node<<" ";
         
//           for(auto nbr:l[node]){
//               if(dist[nbr]==INT_MAX){
//               q.push(nbr);
//               dist[nbr]=dist[node]+1;
//           }
//       }
//       }
//       //print the dist to every node
//         for(auto node_pair:l)    {
//             T node = node_pair.first;
//             int d = dist[node];
//             cout<<"Node "<<node<<"--> Dist from src "<<d<<endl;
//         }
      
//   }

void dfs_helper(T src, map<T,bool>&visited){
    cout<<src<<" ";
    visited[src] = true;
    
    for(T nbr: l[src]){
        if(!visited[nbr]){
            dfs_helper(nbr,visited);
        }
    }
}


void depthFS(){
    map<T,bool>visited;
    
    for(auto p: l){
        T node = p.first;
        visited[node] = false;
    }
    
    // dfs_helper(src,visited);
    int cnt = 1;
    //iterate over all the nodes
    
    for(auto p:l){
        T node = p.first;
        if(!visited[node]){
            cout<<"Component "<<cnt<<" --> ";
            dfs_helper(node, visited);
            cnt++;
            cout<<endl;
        }
    }
}
  
  
  
  };


int main(){
    
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(3,0);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,8);
    
    // g.breadthFS(0);
    g.depthFS();
    
    
    return 0;
}
