#include <iostream>
#include <list>
#include <algorithm>
using namespace std;





class Graph {
    
  public:
  int V;
  list<int> *l;
  
  Graph(int V){
      this->V = V;
      l = new list<int>[V];
  }
  
  void addEdge(int x, int y){
      l[x].push_back(y);
      l[y].push_back(x);
  }
  
  void printList(){
      for(int i =0;i<V;i++){
          cout<<"Vertex"<<i<<"->";
          for(auto nbr:l[i]){
              cout<<nbr<<" ,";
          }
          cout<<endl;
      }
  }
    
};


int main(){
    
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(0,4);
    g.printList();
    
    
    return 0;
}
