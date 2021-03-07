//binary search
//aggressive cows

#include <bits/stdc++.h>
using namespace std;
#define ll long

bool canPlaceCows(int *shelter, int n, int cows, int min_step){

	int lastCow = shelter[0];
	int cnt=1;

	for(int i=1;i<n;i++){
		if(shelter[i]-lastCow>=min_step){
			lastCow = shelter[i];
			cnt++;
			if(cnt==cows){
				return true;
			}
		}

	}
return false;

}






int main()
{
		#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif
 	int shelter[] = {1,2,4,8,9};
 	int cows = 3;
 	int n=5;

 	//binary search algorithm

 	int s=0;
 	int e= shelter[n-1] - shelter[0];
 	int ans=0;

 	while(s<=e){
 		int mid = (s+e)/2;
 		
 		bool keepCow = canPlaceCows(shelter,n,cows,mid);

 		if(keepCow){
 			ans = mid;
 			s= mid+1;
 		}
 		else e = mid-1;
 	}

 	cout<<ans;

 	// aggrcw(shelter, n , cows);


	return 0;
}



