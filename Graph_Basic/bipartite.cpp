#include<bits/stdc++.h>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

bool dfs_helper(vector<int> graph[],int node, int * visited,int parent, int color){
    visited[node] = color;
    
    for(auto nbr: graph[node]){
        if(visited[nbr]==0){
            int sub_prob = dfs_helper(graph,nbr, visited,node,  3-color);
            if(sub_prob==false){
                return false;
            }
        }
        else if (nbr!= praent and color == visited[nbr]){
            return false;
        }
    }
    return true;
}



bool dfs (vector<int>graph[], int N)
{
    int visited[N] = {0}; //0-Not visited, 1 visited color 1, 2 visited and color 2
    int color =1;
    dfs_helper(graph,0,visited,-1, color);
    
    for(int i=0;i<N;i++){
        cout<<i<<" - "<<visite[i]<<endl;
    }
}





int main(){
    
    int N,M;
    //N -- Nodes, M -- Edges
    
    cin>>N>>M;
    
    //define graph
    //vector of arrays
    vector<int> graph[N];
    
    while(M--){
        int x,y;
        cin>>x>>y;
        
        //all are bi-directional Edges
        //addEdge function
        
        graph[x].push_back(y);
        graph[y].push_back(x);
        
    }
    
    if(dfs(graph,N)) cout<<"Graph Bipartite";
    else
    cout<<"Graph not bipartite";
    
    //BFS or DFS by colouring the node at each step (current node has colour 1, nbr should have colour 2)
    
    return 0;
}

