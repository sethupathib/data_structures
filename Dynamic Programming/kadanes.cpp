#include <bits/stdc++.h>
using namespace std;


int maxSum(int *a, int n ){

	int sum[100]={0};
	int sum2;
	for(int i=0;i<n;i++){
		   sum2+=a[i];
		for(int j=i+1;j<n;j++){
			sum[j] = sum2+a[j];
			if(sum[j]<0){
				sum[j]=0;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<sum[i]<<" ";
	}
cout<<"---------------"<<endl;
int max =0;
for(int i=0;i<n;i++)
{
	if(max<sum[i]){
		max = sum[i];
	}

}


	
return max;

	}

//DP optimisation

int maxSum1(int *a, int n){
	int dp[100] = {0};
	dp[0] = a[0]>0?a[0]:0;
	int max_so_far = dp[0];

	for(int i=1;i<n;i++){
		dp[i] = dp[i-1] + a[i];
		if(dp[i]<0){
			dp[i] = 0;
		}
		max_so_far = max(dp[i],max_so_fa ); 
	}
	return max_so_far;
}

int maxSum3(int *a, int n){
	int csum = a[0];
	int osum = a[0];
	for(int i=1;i<n;i++){
		if(csum>=0){
			csum+=a[i];
		}
		else csum = a[i];
	}
	if(csum>osum){
		osum = csum;
	}
	return osum;
}


int main(){
	int a[] = {-3,2,5,-1,6,3,-2,7,-5,2};
	int n = sizeof(a)/sizeof(int);

	// cout<<maxSum(a,n);
	cout<<maxSum3(a,n);
	
	return 0;
}
