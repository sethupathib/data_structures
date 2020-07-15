//#include <bits/stdc++.h>
 #include <iostream>
// #include<algorithm>
using namespace std;
void rearrange(int *arr,int l)
{
//Write code here, make changes in the same array 
    int pos[100],neg[100],k=0,m=0,n=0;
//     
    for (int i=0;i<l;i++)
    {
        if(arr[i]>0)
           pos[i]=arr[i];
      }
    for(int i =0;i<l;i++)
    {
        
         if(arr[i]<0)
        {
            neg[k]= arr[i];
            k++;
    }
    }
sort (pos,pos + l/2);
sort(neg,neg+ l/2, greater<int>());

for(int i=0;i<l;i+=2)
{
    arr[i]=pos[m];
    m++;
}
    for(int i=1;i<l;i+=2)
    {
        arr[i]=neg[n];
        n++;
    }
    
    for(int i=0;i<l;i++)
    {
        cout<<arr[i];
    }
    
    // for(int i=0;i<l/2;i++)
// {
//  cout<<pos[i];
// }
// cout<<"\t\t"<<endl;
// for(int i=0;i<l/2;i++)
// {
//  cout<<neg[i];
// }


}




