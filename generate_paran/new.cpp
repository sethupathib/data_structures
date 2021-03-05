//recursion
//generate subseq
#include <bits/stdc++.h>
using namespace std;
#define ll long

// const int N=3005;

void generatebrack(char *out, int n, int i, int open, int close){
		if(i==2*n)
		{
			out[i] = '\0';
			cout<<out<<endl;

		return;

		}
		//rec case
		//open<n
		//2. close<open
		if(open<n){
			out[i] = '(';
			generatebrack(out,n,i+1,open+1,close);
		}

		if(close<open){
			out[i] = ')';
			generatebrack(out,n,i+1,open,close+1);
		}

		return;
}




int main()
{
		#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif
 	int n;
 	cin>>n;
char out[10];
generatebrack(out,n,0,0,0);

	return 0;
}



