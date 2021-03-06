//recursion
//generate subseq
#include <bits/stdc++.h>
using namespace std;
#define ll long

// const int N=3005;


int profit(int n, int C, int *price, int *wt){


	//base 
	if(n==0 || C==0){
		return 0;
	}

	//rec
	int inc=0;
	int exc =0;
	int ans=0;
	if(wt[n-1]<=C){
	inc = price[n-1] + profit(n-1,C-wt[n-1],price, wt);
	}
	exc = profit(n-1,C,price,wt);
	
	ans = max(inc,exc);


	return ans;
}


int main()
{
		#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif

 	int n=4;
 	int C=7;

 	int price[4] = {40,20,30,100};
 	int wt[4] = {1,2,3,5};
 	cout<<profit(n,C,price, wt);

	return 0;
}



