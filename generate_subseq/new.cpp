//recursion
//generate subseq
#include <bits/stdc++.h>
using namespace std;
#define ll long

// const int N=3005;

void generatesubseq(char *in, char *out, int i, int j){
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}

	//rec case 1. a included
	out[j] = in[i];
	generatesubseq(in,out,i+1,j+1);

	//rec case 2. a excluded
	generatesubseq(in,out,i+1,j);

}




int main()
{
		#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif
char in[] = "abc";
char out[10];
generatesubseq(in,out,0,0);

	return 0;
}



