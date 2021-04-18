#include <bits/stdc++.h>
using namespace std;


//method signature -- 
//n = no. of nodes
//src = source node
//g = edge list of the graph
vector<int> bellman_ford(int V, int src, vector<vector<int> > g){

	vector<int> dist(V+1,INT_MAX);
	dist[src] = 0;

	//relax all the edges V-1 times
	for(int i=0;i<V-1;i++){
		for(auto edge:g){
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			//checking for overflow
			if(dist[u]!= INT_MAX and dist[u] + wt < dist[v]){
				 dist[v] = dist[u]+ wt;
			}
		}
	}
//negative cycle detection in the graph i.e negative weight cycle
	for (auto edge:g){
		int u = edge[0];
		int v = edge[1];
        int wt = edge[2];
		if(dist[u]!= INT_MAX and dist[u] + wt < dist[v]){
				//  dist[v] = dist[u]+ wt;
                cout<<"Negative Weight Cycle Found "<<endl;
                exit(0);

	}
}

return dist;
}



int main(){

	int m,n;
	//m = edges
	//n = nodes
	cin>>n>>m;

	vector< vector <int> > g;
	//graph representation in the form of edge list

	for(int i=0;i<m;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		g.push_back({x,y,wt});
	}

	//bellman ford algorithm
	vector<int> distances = bellman_ford(n,1,g);
	for (int i=1;i<=n;i++){
		cout<<"Node "<<i<<" is at a distance "<<distances[i]<<endl;
	}
	return 0;
}
