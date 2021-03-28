#include <iostream>
#include <map>
#include <list>
using namespace std;


//defining graphs
template <typename T>
class Graph {

map<T,list<T> > l;
public:

void addEdge(int x, int y){
	l[x].push_back(y);
}


bool cycle_helper(int node, bool *visited, bool *stack){

	visited[node] = true;
	stack[node] = true;
//	cout<<src<<" ";



	//2 cases
 


	for(auto nbr : l[node]){

	//case 1

	if(stack[nbr] == true)
	return true;

	//case 2

	if(!visited[nbr]){
	bool cycle_mila = cycle_helper(nbr,visited,stack);
	if(cycle_mila == true)
	return true;
	}
}


	//leave a node	
	stack[node] = false;
	return false;
}



bool isCyclic(){

	bool *visited = new bool[10] ;
	bool *stack = new bool[10];

	for(int i=0;i<7;i++){
	visited[i] = stack[i] = false;
}
	

	return cycle_helper(0,visited,stack);
	}


};

int main()
{


Graph<int> g;
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(1,5);
g.addEdge(5,6);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(4,2);
//g.isCyclic();


	if(g.isCyclic()) 
	cout<<"cycle present"<<endl;
  else cout<<"cycle not present"<<endl;

return 0;
}



