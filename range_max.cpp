//Binary Indexed Tree
//Fenwick Tree

#include <bits/stdc++.h>
using namespace std;

int a[1000];
int BIT[1000] = {0};


//range sum query
// void update(int i, int inc, int N){
// 	while(i<=N){
// 		BIT[i]+=inc;
// 		i+= (i&(-i));
// 	}
// }

//range max query
void update(int i, int val, int N){
	while(i<=N){
		BIT[i] = max(BIT[i],val);
		i+= (i&(-i));
	}
}



// int query(int i){
// 	int sum=0;
// 	while(i>0){
// 		// sum+= BIT[i];
// 		i-= (i&(-i));
// 	}
// 	return sum;
// }
//max query
int query(int i){
	int ans=0;
	while(i>0){
		// sum+= BIT[i];
		ans = max(ans,BIT[i]);
		i-= (i&(-i));
	}
	return ans;
}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif

 	int n;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		update(i,a[i],n);
 	}
 	// for(int i=1;i<=n;i++){
 	// 	cout<<a[i]<<" ";
 	// }
 	int q;
 	cin>>q;
 	// while(q--){
 	// 	int l,r;
 	// 	cin>>l>>r;
 	// 	cout<<query(r) - query(l-1)<<endl;
 	// }

 	while(q--){
 		int idx;
 		cin>>idx;
 		cout<<query(idx)<<endl;
 	}


		return 0;
}










