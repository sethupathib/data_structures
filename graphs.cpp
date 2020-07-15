//#include <iostream>
//#include <vector>
//
//int main ()
//{
//  std::vector<int> myvector = {10,20,30,40,50};
//
//  std::cout << "myvector contains:";
//
//  for (auto it = myvector.begin(); it != myvector.end(); ++it)
//    std::cout << ' ' << *it;
//  std::cout << '\n';
//
//  return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the directed graph
		for (auto &edge: edges)
		{
			// insert at the end
			adjList[edge.src].push_back(edge.dest);

			// Uncomment below line for undirected graph
			// adjList[edge.dest].push_back(edge.src);
		}
	}
};

// print adjacency list representation of graph
void printGraph(Graph const& graph, int N)
{
	for (int i = 0; i < N; i++)
	{
		// print current vertex number
		cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (int v : graph.adjList[i])
			cout << v << " ";
		cout << endl;
	}
}

// Graph Implementation using STL
int main()
{
	// vector of graph edges as per above diagram.
	// Please note that initialization vector in below format will
	// work fine in C++11, C++14, C++17 but will fail in C++98.
	vector<Edge> edges =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// Number of nodes in the graph
	int N = 6;

	// construct graph
	Graph graph(edges, N);

	// print adjacency list representation of graph
	printGraph(graph, N);

	return 0;
}

_______________________________________________________________________________________________



#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

//this code is implemented using STL. (vectors essentially)
//taking help of GFG tutorials




void addEdge(vector<int> adj[],int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
	
	}
void printGraph(vector<int> adj[], int V)
{
	vector <int>:: iterator it;
	
	for(int v=0;v<V;++v)
	{
		cout<<v<<endl;
		cout<<"\n adjacency list of vertices"<< v<< "\n head";

		//for(auto x: adj[V])
		for(it = adj->begin();it!=adj->end();it++)
		{
		
		cout<<*it<<"->";
		cout<<"\n";
		}
		}
	
	
	}



//void printGraph(vector<int> adj[], int V) 
//{ 
//    for (int v = 0; v < V; ++v) 
//    { 
//        cout << "\n Adjacency list of vertex "
//             << v << "\n head "; 
//        for (auto x : adj[v]) 
//           cout << "-> " << x; 
//        printf("\n"); 
//    } 
//}


int main()
{

	int V=5;
	//vector <int> adj[V];
	vector<int> adj[V]; 
    	addEdge(adj, 0, 1); 
    	addEdge(adj, 0, 4); 
    	addEdge(adj, 1, 2); 
    	addEdge(adj, 1, 3); 
    	addEdge(adj, 1, 4); 
    	addEdge(adj, 2, 3); 
    	addEdge(adj, 3, 4); 
    	printGraph(adj, V);
	return 0;
	}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//// data structure to store graph edges
//struct Edge {
//	int src, dest;
//};
//
//// class to represent a graph object
//class Graph
//{
//public:
//	// construct a vector of vectors to represent an adjacency list
//	vector<vector<int>> adjList;
//
//	// Graph Constructor
//	Graph(vector<Edge> const &edges, int N)
//	{
//		// resize the vector to N elements of type vector<int>
//		adjList.resize(N);
//
//		// add edges to the directed graph
//		for (auto &edge: edges)
//		{
//			// insert at the end
//			adjList[edge.src].push_back(edge.dest);
//
//			// Uncomment below line for undirected graph
//			// adjList[edge.dest].push_back(edge.src);
//		}
//	}
//};
//
//// print adjacency list representation of graph
//void printGraph(Graph const& graph, int N)
//{
//	for (int i = 0; i < N; i++)
//	{
//		// print current vertex number
//		cout << i << " --> ";
//
//		// print all neighboring vertices of vertex i
//		for (int v : graph.adjList[i])
//			cout << v << " ";
//		cout << endl;
//	}
//}
//
//// Graph Implementation using STL
//int main()
//{
//	// vector of graph edges as per above diagram.
//	// Please note that initialization vector in below format will
//	// work fine in C++11, C++14, C++17 but will fail in C++98.
//	vector<Edge> edges =
//	{
//		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
//		{ 3, 2 }, { 4, 5 }, { 5, 4 }
//	};
//
//	// Number of nodes in the graph
//	int N = 6;
//
//	// construct graph
//	Graph graph(edges, N);
//
//	// print adjacency list representation of graph
//	printGraph(graph, N);
//
//	return 0;
//}


_______________________________________________________________________________