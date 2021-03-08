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
	updateRangeLazy(tree,mid,se,l,r,incr,2*idx+1);
	tree[idx] = min(tree[2*idx],tree[2*idx+1]);
	return;
}