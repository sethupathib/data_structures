#include <bits/stdc++.h>
using namespace std;

int solve(int *wines, int i, int j, int y, int dp[][100])
{
	//base case

	if(i>j){
		return 0;
	}

	//lookup
	if(dp[i][j]!=0){
		return dp[i][j];
	}

	//rec case
	int op1= wines[i]*y + solve(wines,i+1,j,y+1,dp);
	int op2= wines[j]*y + solve(wines,i,j-1,y+1,dp);
	dp[i][j] = max(op1,op2);
	return dp[i][j];
}
int main(){
	int wine_price[] = {2,3,5,1,4};
	int dp[100][100] = {0};
	int y = 1;
	int n = sizeof(wine_price)/sizeof(int);
	cout<<solve(wine_price,0,n-1,y,dp)<<endl;
	return 0;
}
