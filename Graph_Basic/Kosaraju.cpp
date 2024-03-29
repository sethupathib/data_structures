#include <bits/stdc++.h>

using namespace std;





void dfs(vector<int> graph[], int i, bool *visited, vector<int>&stack){
	visited[i] = true;
	cout<<i;

	for(auto nbr: graph[i]){
		if(!visited[nbr]){
			dfs(graph,nbr, visited, stack);

		}
	}
	// cout<<endl;
	stack.push_back(i);
}

void dfs2(vector<int> graph[], int i, bool *visited){
	visited[i] = true;
	cout<<i;

	for(auto nbr: graph[i]){
		if(!visited[nbr]){
			dfs2(graph,nbr, visited);

		}
	}
	
}



void solve( vector<int>*graph, vector<int>* rev_graph,int N){

	bool visited[N];
	memset(visited,0,N);
	vector<int> stack;

	//step -1 -- store the vertices according to dfs finish time
	for(int i=0;i<N;i++){
		if(!visited[i]){
			dfs(graph,i,visited,stack);
		}
	}
	cout<<endl;

	//ordering  = stack
	//step 2 reverse graph
	//step 3 - do dfs according to the ordering given in the stack


//reset visited array for the 3rd step i.e DFS #2

memset(visited,0,N);
char component_name = 'A';
for(int x = stack.size()-1;x>=0;x--){
	int node = stack[x];
	if(!visited[node]){
		cout<<"Component "<<component_name<<"-->";
		dfs2(rev_graph,node,visited);
		cout<<endl;
		component_name++;
	}
}
}
int main(){

	int N; //nodes
	cin>>N;
	vector<int>graph[N];
	vector<int>rev_graph[N];

	int m; //edges
	cin>>m;

	while(m--){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		rev_graph[y].push_back(x);
	}
	cout<<endl;
	solve(graph,rev_graph,N);
	return 0;
}

