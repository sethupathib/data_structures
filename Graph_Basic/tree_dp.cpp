//Find the smallest node value in a sub-tree of x
#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> g[N];
int dp[N];


void dfs(int current, int parent){
	dp[current] = current;
	for(auto x:g[current]){
		if(x!=parent){
			dfs(x,current);
			dp[current] = min(dp[current],dp[x]);
			
		}
	}

	return;
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif
	
 	int n;
 	cin>>n;
 	for(int i=0;i<n;i++){
 		int x,y;
 		cin>>x>>y;
 		g[x].push_back(y);
 		g[y].push_back(x);

 	}
	dfs(1,0);

	for(int i=1;i<=n;i++){
		cout<<i<<" "<<dp[i]<<"\n";
	}
	return 0;
}



