#include <bits/stdc++.h>
using namespace std;

int findMax(int *a, int n){
	int temp = a[0];
	for(int i=1;i<n;i++){
		if(a[i]>temp){
			temp = a[i];
		}
	}
	return temp;
}

void printArray(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

void count_sort(int *a, int n){
	int k = findMax(a,n);
	//k=9 in this case
	int count[10]={0};
	int b[17]={0};
	for(int i=0;i<n;i++){
		++count[a[i]];
	}

	for(int i=1;i<=k;i++){
		count[i]+= count[i-1];
	}

	for(int i=n-1;i>=0;i--){
		b[--count[a[i]]] = a[i];
	}

	for(int i =0;i<n;i++){
		a[i] = b[i];
	}
	
	printArray(a,n);
}

int main(){
	int A[] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
	int n = sizeof(A)/sizeof(int);
	count_sort(A,n);
	return 0;
}
