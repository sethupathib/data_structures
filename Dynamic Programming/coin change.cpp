#include <bits/stdc++.h>
using namespace std;
int dp[100] = {0};

// int coinchange(int n,int *dp){
// int coins[3] = {1,7,10};

// //base case
// if(n==0){
// 	return dp[0]=0;
// }

// //look-up
// if(dp[n]!=0){
// 	return dp[n];
// }

// //recursive case
// int op1,op2,op3;
// op1=op2=op3= INT_MAX;

// 	for(i=0;i<3;i++){
// 		if(n-coins[i]>=0){}
// 	}
// 	op1 = coinchange(n-coins[1],dp);
// 	op2 = coinchange(n-coins[2],dp);
// 	op3 = coinchange(n-coins[3],dp);
// int ans = min(min(op1,op2),op3)+1;
// return ans;
// }

int coinchange(int n, int coins[], int T, int dp[]){

	//base case 
	if(n==0){
		return 0;
	}
	//lookup
	if(dp[n]!=0){
		return dp[n];
	}

	//rec case
	int ans = INT_MAX;
	for(int i=0;i<T;i++){
		if(n-coins[i]>=0){
			int subprob = coinchange(n-coins[i],coins,T,dp);
			ans = min(ans,subprob+1);
		}
	}
	dp[n] = ans;
	return dp[n];
}

int coinchange(int N , int coins[], int T){
	int dp[100] = {0};

	for(int n=1;n<=N;n++){
		dp[n] = INT_MAX;
		for(int i=0;i<T;i++){
			if(n-coins[i]>=0){
				int subprob = dp[n-coins[i]];
				dp[n] = min(dp[n],subprob+1);
			}
		}
	}
	return dp[N];
}



int main(){
	int N=15;
	int coins[] = {1,7,10};
	int T = sizeof(coins)/sizeof(int);
	// cout<<coinchange(N,coins,T,dp);
	cout<<coinchange(N,coins,T); // this is the bottom up approach
	return 0;
}










