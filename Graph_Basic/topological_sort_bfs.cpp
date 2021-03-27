// #include <bits/stdc++.h>
// #include <map>
// #include <list>
// using namespace std;

// class Graph{
//     list<int>*l;
//     int V;
    
//     public:
    
//     Graph(int V){
//         this->V = V;
//         l = new list<int>[V];
//     }
    
    
//     void addEdge(int x, int y){
//         l[x].push_back(y);
//     }
    
//     void topological_sort(){
//         int *indegree = new int[V];
        
//         //make indegree of all nodes as 0
//         for(int i=0;i<V;i++){
//             indegree[i]= 0;
//         }
        
//           //update the indegree by traversing edges x->y
        
//         for(int i=0;i<V;i++){
            
//             for(auto y: l[i]){
//                 indegree[y]++;
//             }
//         }
//         //bfs 
        
//         queue<int> q;
//         //1. find nodes with 0 indegree
//         for(int i=0;i<V;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
        
      
        
        
//         //start removing elements from the queue
//         while(!q.empty()){
//             int node = q.front();
//             cout<<node <<" ";
//             q.pop();
            
//             //iterate over nbrs of that node and reduce the indegree by 1
//             for(auto nbr:l[node]){
//                 indegree[nbr]--;
//                 if(indegree[nbr]==0){
//                     q.push(nbr);
//                 }
//             }
//         }
//     }
    
// };



// int main(){
    
//     Graph g(4);
//     g.addEdge(1,2);
//     g.addEdge(1,3);
//     g.addEdge(2,4);
//     g.addEdge(3,4);
//     // g.addEdge(4,5);
//     g.topological_sort();
    
    
//     return 0;
// }



#include <iostream>
#include <queue>
#include <list>
#include <map>
using namespace std;

class Graph{
	map<int,list<int>> l;
public:
	//Creating the Graph
	void addedge(int x, int y){
		l[x].push_back(y);
	}

	void Topological_sort(){
		int *indegree = new int[100]();//added (): this will initialise all entries to 0

		//Setting all indegrees to 0.
		for(auto nodes:l){  // this will intilaise only   those elements that are there in the map 
			indegree[nodes.first] = 0;
		}

		//Setting all indegrees to their value.
		for(auto x:l){
			for(auto y:x.second){
				indegree[y]++;
			}
		}

		queue<int> q;
		for(auto node:l){
			if(indegree[node.first]==0){
				q.push(node.first);
			}
		}

		while(!q.empty()){
			int temp = q.front();
			q.pop();
			cout<<temp<<" ";
			for(auto p:l[temp]){
				indegree[p]--;
				if(indegree[p]==0){
					q.push(p);
				}
			}
		}
	}
};

int main(){
	Graph g;
	g.addedge(0,4);
	g.addedge(1,4);
	g.addedge(1,3);
	g.addedge(4,2);
	g.addedge(4,5);
	g.addedge(3,5);
	g.addedge(2,5);
	g.Topological_sort();
	return 0;
}	
