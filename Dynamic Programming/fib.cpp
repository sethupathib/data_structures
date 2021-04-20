#include <bits/stdc++.h>
using namespace std;

int dp[100];



int fib(int n){
	if(n==0 or n==1) {
		return n;
	}
	int ans = fib(n-1) + fib(n-2);
	return ans;
}


int fib_dp(int n){
	if(n==1 or n==0){
		return n;
	}
	if(dp[n]!=0){
		return dp[n];

	}
	 int ans = fib(n-1) + fib(n-2);
	 return dp[n] = ans;
}

int bu_fib(int n){
	dp[1] =1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];

}

int fib_space_opt(int n){
	if(n==0 or n==1){
		return n;
	}
	int a =0;
	int b=1; 
	int c;
	for(int i=2;i<=n;i++){
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}


int main(){

int n;
cin>>n;
cout<<fib_space_opt(n)<<endl;
	return 0;
}
