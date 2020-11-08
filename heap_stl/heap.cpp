// Heap STL

// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> v = {20,30,40,25,15};
	make_heap(v.begin(),v.end());
	cout<<v.front()<<endl;
	v.push_back(100);
	v.pop_back(20);
	cout<<v.front();


  return 0;
}
