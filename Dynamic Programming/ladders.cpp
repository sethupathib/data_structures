#include <bits/stdc++.h>
using namespace std;
int dp[100] = {0};


int ladders(int n, int k, int *dp){

	//base case
	if(n==0){
		return 1;
	}

	if(dp[n]!=0){
		return dp[n];
	}

	int ans = 0;
	for(int i=1;i<=k;i++){
		if(n-i >=0){
			ans += ladders(n-i,k,dp);
		}
	}

	return dp[n] = ans;
}

//Bottom Up Approach

int ladders1(int n, int k){
	int dp[100] = {0};
	dp[0] = 1; //start case
	for(int i=1;i<=n;i++){
		dp[i] = 0;
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				dp[i] += dp[i-j];
			}
		}
	}

	for(int i=0;i<=n;i++){
		cout<<dp[i]<< " ";
	}
	return dp[n];
}



int main(){

int n=4,k=3;
	// cout<<ladders(n,k,dp);
	cout<<ladders1(n,k);
	return 0;
}
