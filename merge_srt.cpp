//recursion
//merge sort
#include <bits/stdc++.h>
using namespace std;
#define ll long

// const int N=3005;

void merge (int *a, int s, int e){
	
	int mid = (s+e)/2;
	int i=s;
	int k=s;
	int j=mid+1;
	int temp[10];
	
	
	

	while(i<=mid && j<=e){
		if(a[i]<a[j]){
			temp[k++] = a[i++];
		}
		else temp[k++] = a[j++];
	}

	while(i<=mid){
		temp[k++] = a[i++];
	}
	while(j<=e){
		temp[k++] = a[j++];
	}
	// k--;
	for(int i =0;i<=e;i++){
		a[i]=temp[i];
	}

}


void solve(int *a,int s, int e){

	

	if(s>=e) return;
	int mid = (s+e)/2;
	solve(a,s,mid);
	solve(a,mid+1,e);
	merge(a,s,e);



}

int main()
{
		#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif

int n;
int a[10];
cin>>n;
// cout<<"test"<<endl;
for(int i =0;i<n;i++){
	cin>>a[i];
}
solve(a,0,n-1);

for(int i =0;i<n;i++){
	cout<<a[i];
}

	return 0;
}



