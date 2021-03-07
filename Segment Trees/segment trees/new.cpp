//binary search
//aggressive cows

#include <bits/stdc++.h>
using namespace std;
#define ll long


void buildTree(int *a, int s, int e, int *tree, int idx){

	//base case

	if(s==e){
		tree[idx] = a[s];
		return;
	}

	//rec case
	//left sub tree
	int mid = (s+e)/2;
	buildTree(a,s,mid,tree,2*idx);
	buildTree(a,mid+1,e,tree,2*idx+1);
	tree[idx] = min(tree[2*idx],tree[2*idx +1]);
	return ;
}




int main()
{
		#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif
 	
 	int a[] = {1,3,2,-5,6,4};
 	int n= sizeof(a)/sizeof(int);

 	int *tree = new int[4*n+1];

 	buildTree(a,0,n-1,tree,1);

 	//print the tree

 	for(int i=1;i<=13;i++){
 		cout<<tree[i]<< " ";
 	}

	return 0;
}



