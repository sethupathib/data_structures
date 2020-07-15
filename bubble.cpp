#include <bits/stdc++.h>
using namespace std;

//bubble sort --> the largest element is pushed to the right most part of the array



void swap(int *A,int *B)
{
	int temp=0;
	temp = *A;
	*A=*B;
	*B = temp;
	}

void bubbleSort(int A[],int n)
{
for(int k=0;k<n-1;k++)
{
	int flag=0;
	for(int i=0;i<n-k-1;i++)
	{
		if (A[i]>A[i+1])
		{

			swap(&A[i],&A[i+1]);
			flag=1;
		}
		}
	//	cout<<"a";
		if (flag==0) break;
	}

	cout<<"Sorted Order is -->";
	for(int j=0;j<6;j++)
	{
		cout<<A[j]<<" ";
		}

}


int main()

{
	int A[] = {2,7,4,1,5,3};
	bubbleSort(A,6);

	return 0;
	}