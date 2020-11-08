//
//  main.cpp
//  graph
//
//  Created by Sethupathi on 07/11/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V =V;
        l = new list<int>[V];
    }
    
    void addEdge(int a, int b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
        
    }
    
    void printList(){
        
        for(int i=0;i<V;i++){
            cout<<"Vertex "<<i<<"->";
            for(auto x: l[i]){
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.printList();
    return 0;
}
