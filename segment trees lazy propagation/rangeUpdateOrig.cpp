void updateRangeLazy(int *tree,int ss,int se,int l,int r,int inc,int index){
    //First Step - Never we go down if you have lazy value at node, first resolve it 
    
    if(lazy[index]!=0){
        
        tree[index] += lazy[index];
        
        //if not a leaf node 
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    // Out of Bounds 
    if(ss>r || l > se){
        return;
    }
    // Complete Overlap- Beeche Raste Mei hi Return krna 
    if(ss>=l && se<=r){
        tree[index] += inc;
        
        // Pass the lazy value to children 
        if(ss!=se){
            lazy[2*index] +=  inc;
            lazy[2*index+1] += inc;
        }
    return;
    }
    
    //Call on Left and Right 
    int mid = (ss+se)/2;
    updateRangeLazy(tree,ss,mid,l,r,inc,2*index);
    updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    
    return;
    
}