//binary search
//iterative
#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n, int m)
{
	int start = 0;
	int end = n-1;
	int mid;

	while(start<=end){
		mid = (start+end)/2; //start + (end-start)/2;
		if(a[mid]==m)
			return mid;
		if(m>a[mid])
			start = mid+1;
		else
			end=mid-1;
	}
	return -1;
}
//recursive
int solve(int a[],int start, int end, int m)
{
	
	if(start>end) return -1;
	int mid = (start + end)/2;
	if(m==a[mid]) return mid;

	if(m<a[mid])
		return solve(a,start,mid-1,m);
	else
		return solve(a,mid+1,end,m);
	

	return -1;
}


int main()
{
int a[10] = {1,2,4,2,3,1};
  int k;
  cin>>k;
  solve(a,k);

return 0;
}
