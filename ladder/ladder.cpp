#include <iostream>
using namespace std;



int ladder(int n, int k){

if(n==0) return 1;
  if(n<0) return 0;
  
 int  sum = 0;
  for(int i =1;i<=k;i++)
  {
 sum+= ladder(n-i,k); 
  
  }
  
  return sum;
}







int main()
{
  int n,k;
  cin>>n>>k;
  cout<<"No. of Ways --> "<<ladder(n,k);
  
  return 0;
}
