//
//  main.cpp
//  dijkstas sssp
//
//  Created by Sethupathi on 12/11/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;



template<typename T>
class Graph{
    unordered_map<T, list<pair<T,int>> > m;
public:
    void addEdge(T u, T v, int dist, bool bidir=true){
        
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
        
    }
    
    //printing adjacency list
    //iterate over all the key value pairs in the map
    
    void printAdj(){
        for(auto j:m){
            cout<<j.first<<"-->";
//            auto m = j.first;
            for(auto x: j.second){
//                cout<<"("<<x.first<<","<<x.second<<")";
                cout<<x.first<<" "<<x.second;
            }
            cout<<endl;
        }
        
    }
    
    
    void dijsktraSSSP(T src){
        unordered_map<T, int> dist;
        for(auto x:m){
            dist[x.first] = INT_MAX;
            
        }
        
        //make a set to find out a node with min distance
        set<pair< int,T> > s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            //find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            //Iterate over the children of the current node
            for (auto childPair: m[node] ){
                if((nodeDist + childPair.second) < dist[childPair.first]){
                    
                    //In the set, updatation of a particular node is not possible
                    //we have to remove the old par, insert the new pair to simulation updation
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    
                    //insert the new pair
                    
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
                
            }
            
        }
        for(auto d:dist){
            cout<<d.first<<"is located at a distance of  "<<d.second<<endl;
        }
    }
};










int main(int argc, const char * argv[]) {
    
    Graph <int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
//    g.printAdj();
    g.dijsktraSSSP(1);
    

    
    return 0;
}
