//recursion quick sort
#include <bits/stdc++.h>
using namespace std;
#define ll long

void swap(int *first, int *second){
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}


int partition(int *a,int s, int e){
	
	// int j =s;
	int pivot = a[e];
	int i=s-1;
	for(int j=s;j<=e-1;j++){
		if(a[j]<pivot){
			i=i+1;
			swap(a[i],a[j]);

		}
		// j=j+1;
	}
	swap(a[i+1],a[e]);
	return i+1;

}

void solve(int *a,int s,int e){

	if(s>=e){
		return;
	}

	int p = partition(a,s,e);
	// printfn(a,n);

	solve(a,s,p-1);
	solve(a,p+1,e);
}



void printfn(int *a,int n){
for(int i=0;i<n;i++){
	cout<<a[i]<<" ";
}

}

int main()
{
		#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif

int a[1000],n;

cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i];
}

solve(a,0,n-1);
printfn(a,n);
	return 0;
}



