//Prb -- Min steps to 1
//conditions --
// n/2, n/3, n-1

#include <bits/stdc++.h>
using namespace std;
int dp[100]={0};


// Bottom Up Approach
int solve1(int n){
// int dp[100]={0};
	dp[1] = 0;

	for(int i=2;i<=n;i++){
		int a,b,c;
		a=b=c=INT_MAX;
		if((n%3)==0){
			a = dp[i/3];
		}
		if((n%2) ==0){
			b = dp[i/2];
		}
			c = dp[i-1];
 		dp[i] = min(min(a,b),c) +1;

	}
return dp[n];
}


//Rec + Mem Approach

int solve(int n,int *dp){
	//base case
	if(n==1){
		return dp[1] = 0;
	}
	int a,b,c;
	a=b=c=INT_MAX;

	if(n%3 == 0){

		a = solve(n/3,dp);
			}
	if(n%2 ==0){
		b = solve(n/2,dp);
	}
	 
	 c = solve(n-1,dp);
	 return dp[n] = min(min(a,b),c) +1;



}
int main(){
	
	int n=6;
	// cout<<solve(n,dp);
	cout<<solve1(n);


	return 0;
}






