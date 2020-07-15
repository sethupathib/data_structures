#include <bits/stdc++.h>
using namespace std;



//selection sort

void selectionSort(int A[], int n)

{
	for(int i=0;i<n-1;i++)     //we need to do n-2 passes
	{
		int iMin = i;		//ith position : elements from i to n-1 are candidates
		
		for(int j=i+1;j<n;j++)   
		{
			if(A[j]<A[iMin])
				iMin = j;   //update the index of minimum element
			}
		
						//swap 
			int temp = A[i];
			A[i] = A[iMin];
			A[iMin] = temp;
		}
	
	
	}

int main()
{
	
	int A[] = {2,7,4,1,5,3};
	selectionSort(A,6);
	

	cout<<"Sorted Elements are"<<endl;
	for(int i=0;i<6;i++)
	{
		cout<<A[i]<<" ";
		}
	
	
	}
