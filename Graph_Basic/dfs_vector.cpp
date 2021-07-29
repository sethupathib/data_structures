#include <bits/stdc++.h>
using namespace std;
const int N=100;
vector<int>gr[N];
int Par[N];

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
    dfs(1,0);
    return 0;
}
