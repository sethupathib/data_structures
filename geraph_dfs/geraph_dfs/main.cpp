//
//  main.cpp
//  geraph_dfs
//
//  Created by Sethupathi on 07/11/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template<typename T>

class Graph {

    map<T,list<T> > l;

public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void dfs_helper(T src, map<T,bool>&visited){
        //recursive function that traverses the graph
        cout<<src<<" ";
        visited[src] = true;
        //go to all neighbors of the visited node.
        for(T nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
            
        }
        
    }

    void dfs(T src){
        map<T,bool> visited;
        //mark all nodes as not visited
        //all nodes will be marked into the map
        
        //initialising all the nodes as not visited should be done only once.
        //so we need to create a dfs_helper function
        for(auto x:l){
            T node = x.first;
            visited[node] = false;
        }
        dfs_helper(src,visited);
    }



};



int main(int argc, const char * argv[]) {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 0);
//    g.addEdge(0, 1);
    g.dfs(0);
    
    return 0;
}
