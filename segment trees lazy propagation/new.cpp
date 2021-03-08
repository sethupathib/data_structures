// //segment trees
// //lazy propagation

#include <bits/stdc++.h>
using namespace std;
int lazy[1000] = {0};




int queryLazy(int *tree, int ss, int se, int qs,int qe, int idx){

	//resolve lazy
	//lazy propagation
	if(lazy[idx]!=0){
		tree[idx]+=lazy[idx];
		//leaf node
		if(ss!=se){
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1]+=lazy[idx];
		}
		lazy[idx] = 0;
	}

	//no overlap
	if(ss>qe || se<qs){
		return INT_MAX;
	}
	//complete overlap
	if(ss>=qs && se<=qe){
		return tree[idx]; 
	}
	//partial overlap
	int mid = (ss+se)/2;

	int leftq = queryLazy(tree,ss,mid,qs,qe,2*idx);
	int rightq = queryLazy(tree,mid+1,se,qs,se,2*idx+1);
	return min(leftq,rightq);
}



void updateRangeLazy(int *tree,int ss, int se, int l, int r,int incr,int idx){
	//resolve lazy
	if(lazy[idx]!=0){
		tree[idx]+=lazy[idx];
		//leaf node
		if(ss!=se){
			tree[2*idx]+=lazy[idx];
			tree[2*idx+1]+=lazy[idx];

		}
			lazy[idx] = 0;
	}


	//no overlap
	//increment

	if(r<ss || l>se){
		return;
	}
//complete overlap
	if(l<=ss && r>=se){
		tree[idx]+=incr;
		if(ss!=se){
			tree[2*idx]+=incr;
			tree[2*idx+1]+=incr;

		}

		return;
	}

	
	//partial overlap

	int mid = (ss+se)/2;
	updateRangeLazy(tree,ss,mid,l,r,incr,2*idx);
	updateRangeLazy(tree,mid+1,se,l,r,incr,2*idx+1);
	tree[idx] = min(tree[2*idx],tree[2*idx+1]);
	return;
}


void buildTree(int *a, int s, int e, int *tree, int idx){

	
	if(s>e) return;
	if(s==e){
		tree[idx] = a[s];
		return;
	}

	int mid = (s+e)/2;
	buildTree(a,s,mid,tree,2*idx);
	buildTree(a,mid+1,e,tree,2*idx+1);
	tree[idx] = min(tree[2*idx],tree[2*idx+1]);
	return;
}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif

int a[] = {1,3,2,-5,6,4};
int n = sizeof(a)/sizeof(int);
int *tree = new int[4*n+1];
buildTree(a,0,n-1,tree,1);

for(int i =0;i<14;i++){
	cout<<tree[i]<<" ";
}
cout<<endl;
updateRangeLazy(tree,0,n-1,2,5,20,1);
updateRangeLazy(tree,0,n-1,1,2,5,1);

cout<<endl;


for(int i =0;i<14;i++){
	cout<<tree[i]<<" ";
}
cout<<endl;
cout<<queryLazy(tree,0,n-1,4,5,1);

	return 0;
}










