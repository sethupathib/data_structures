//
//  main.cpp
//  graph_hash_map
//
//  Created by Sethupathi on 07/11/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    int V;
    //list<int>*l;
    unordered_map<string, list<pair<string,int> > > l;

    
public:
    
    Graph(int V){
        this->V = V;
//        l = new list<int>[V];
    }
    
    void addEdge(string x, string y, bool bidir, int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }
    
    void printList(){
        for (auto x:l){
            string city = x.first;
            list<pair<string,int> > nbrs = x.second;
            cout<<city<<"-->";
            for(auto nbr:nbrs){
                string dest = nbr.first;
                int weight = nbr.second;
                cout<<dest<<" "<<weight<<",";
            }
            cout<<endl;
        }
    }
};

int main(int argc, const char * argv[]) {
   
    Graph g(4);
    g.addEdge("A","B", true, 20);
    g.addEdge("B","D", true, 40);
    g.addEdge("A","C", true, 10);
    g.addEdge("C","D", true, 40);
    g.addEdge("A","D", false, 50);
    g.printList();
    
//    g.addEdge("B", "D");
//    g.addEdge("A", "C");
//    g.addEdge("C", "D");
//    g.addEdge("A", "D");
    return 0;
}
