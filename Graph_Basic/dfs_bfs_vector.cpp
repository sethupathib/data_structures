#include <bits/stdc++.h>
using namespace std;
const int N=100;
vector<int>gr[N];
int Par[N];


void bfs(int src){
    
//   bool visited[] = new bool[N]{0};
    bool visited[N]={0};
  queue<int>q;
  q.push(src);
  
  while(!q.empty()){
      auto node = q.front();
      q.pop();
      cout<<node<<" ";
      for(auto nbr:gr[node]){
          if(!visited[nbr]){
              visited[nbr]=true;
              q.push(nbr);
          }
      }
  }
    
    
}

void dfs(int cur, int par){
    Par[cur]=par;
    cout<<cur<<" ";
    for(auto x:gr[cur]){
    if(x!=par){
        dfs(x,cur);
    }
    }
        return;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    bfs(1);
    return 0;
}


/*
Inputs -- #Nodes and the edge list
19
1 3
1 2
2 4
2 5
5 6
6 7
6 8
6 9
3 10
3 11
10 17
17 18
17 19
11 12
12 13
12 14
12 15
15 16
*/
