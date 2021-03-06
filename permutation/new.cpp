//recursion
//perm

#include <bits/stdc++.h>
using namespace std;
#define ll long

void permute(char *in, int i){

	if(in[i]=='\0'){
		cout<<in<<" , ";
		return;
	}

for(int j=i;in[j]!='\0';j++){

	swap(in[i],in[j]);
	permute(in,i+1);
	swap(in[i],in[j]);

}


}






int main()
{
		#ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
 	freopen("outputs.txt","w",stdout);
 	#endif
 	char in[100];
 	cin>>in;
 	permute(in,0);


	return 0;
}



