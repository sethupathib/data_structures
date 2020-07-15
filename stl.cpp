#include <bits/stdc++.h>
//#include <vector>
using namespace std;

int main()
{
	vector<int> a = {30,40,25,15,35};

	make_heap(a.begin(), a.end());
	a.push_back(65);
	push_heap(a.begin(), a.end());\
	cout<<"after pushing:\n";
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<endl;
	}

	
	return 0;
	}


________________________________________

#include <bits/stdc++.h>
#include <iterator>
#include <vector>


using namespace std;

int main()
{
	vector<int> a;
	for(int i=0;i<6;i++)
		a.push_back(i);
	

	//declaring iterators
	vector<int>:: iterator ptr;

	cout<<a.front();
	cout<<"The elements in the vector are -->";

	for(ptr = a.begin();ptr<a.end();ptr++)
		cout<<*ptr<<endl;


	//advance() function

	vector<int>::iterator ptr1= a.begin();
	//points to 4
	advance(ptr1,3);

	cout<<"The position of the iterator after advancing is -->";

	cout<<*ptr1<<endl;

	//illustrating the use of prev and next

	vector<int>:: iterator p_tr = a.begin();
	vector<int>:: iterator f_tr= a.end();

	//vector<int>:: iterator it = next(p_tr,3);
	//vector<int>:: iterator it1 = prev(f_tr,3);


	//cout<<"position of new iterator using next() is "<<*it<<endl;
	//cout<<"position of new iterator using prev() is "<<*it1<<endl;









return 0;
	}




_______________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;


void showlist(list <int> g)
{
	list <int> :: iterator it;
	for(it = g.begin();it!=g.end();it++)
	{
		cout<<*it<<" ";
		}
	
	}



int main()
{
	
	list <int> glist1,glist2;
	for(int i =0;i<10;i++)
	{
		glist1.push_back(i*2);
		glist2.push_front(i*2);
		}
	cout<<"First List"<<endl;
	showlist(glist1);
	cout<<"\n";
	cout<<"popping one element from the front and back from list1"<<endl;
	glist1.pop_back();
	glist1.pop_front();
	cout<<"\n";
	showlist(glist1);
	cout<<"\n";	
	cout<<"Second List"<<endl;
	showlist(glist2);
	cout<<"\n";	

	cout<<"popping one element from the front and back from list2"<<endl;
	glist2.pop_back();
	glist2.pop_front();
	showlist(glist2);


	cout<<"\n\n\n";
	
	//reversing the linked list
	cout<<"Reversing the linked list #2"<<endl;
	glist2.reverse();
	showlist(glist2);

	//sorting the linked list
	cout<<"\n";
	cout<<"sorted list"<<endl;
	glist2.sort();
	showlist(glist2);
	cout<<"\n";
	cout<<"removing 10"<<endl;
	//removing an item from the L-List
	glist2.remove(10);
	showlist(glist2);

	glist2.clear();

	return 0;
	}
_____________________________________________________________________________

#include <bits/stdc++.h>
#include <map>
#include <iterator>
using namespace std;


int main()
{
	map <int,int> map1;
	map1.insert(pair <int, int> (6,50));
	map1.insert(pair <int, int> (1,40));
	map1.insert(pair <int, int> (4,10));
	map1.insert(pair <int, int> (3,60));
	map1.insert(pair <int, int> (5,80));
	map1.insert(pair <int, int> (7,90));
	map1.insert(pair <int, int> (8,20));
	map1.insert(pair <int, int> (2,220));

	map <int,int> :: iterator it;

	cout<<"\n the map map1 is \n";
	cout<<"\tKEY\tELEMENT\n";


	for(it= map1.begin();it!=map1.end();it++)
	{
		cout<<'\t'<<it->first<<'\t'<<it->second<<endl;
		}
	cout<<endl;
	cout<<"erasing the element in 2nd key"<<endl;	
	map1.erase(2);
	for(it= map1.begin();it!=map1.end();it++)
	{
		cout<<'\t'<<it->first<<'\t'<<it->second<<endl;
		}
	cout<<endl;
	return 0;
	}

___________________________________________________________________________________

#include <bits/stdc++.h>
#include <set>
#include <iterator>

using namespace std;

//void show_set (multiset <int, greater <int> > g)
//{
//	multiset <int, greater <int> >:: itertor it;
//
//	for(it= g.begin(); it!= g.end();it++)
//	{
//		cout<<*it<<' ';
//	}
//		cout<<endl;
//	}

int main()


{
	multiset <int,greater <int> > mset;
	multiset <int,greater <int> >::iterator itr;

	mset.insert(40);
	mset.insert(40);
	mset.insert(30);
	mset.insert(40);
	mset.insert(50);
	mset.insert(60);
	mset.insert(10);
	mset.insert(12);
	mset.insert(1);
	mset.insert(0);

//	mset.sort();
	for(itr=mset.begin();itr!=mset.end();itr++)
		cout<<*itr<<' ';
		cout<<"\n";

	// all the numbers from the beginning till the number 40 appears are deleted.
	mset.erase(mset.begin(),mset.find(40));
//	show_set(mset);

	for(itr=mset.begin();itr!=mset.end();itr++)
		cout<<*itr<<' ';
		cout<<"\n";

	cout<<"the number of times 40 appears here in the list is "<< mset.count(40);

	return 0;
	}

_______________________________________________________________________________________

#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main()
{
	
	pair <int,char> p;
	p.first = 100;
	p.second = 'M';

	pair <int,char> q(19,'S');
	pair <int,char> t;
	t = make_pair(1,'a');
	

	cout<<"first pair details"<<endl;
	cout<<p.first<<endl;
	cout<<p.second<<endl;
	
	cout<<"second pair details"<<endl;
	cout<<q.first<<endl;
	cout<<q.second<<endl;
	
	cout<<"third pair details"<<endl;
	cout<<t.first<<endl;
	cout<<t.second<<endl;

	swap(p,q);


	cout<<"revised first pair details"<<endl;
	cout<<p.first<<endl;
	cout<<p.second<<endl;
	
	cout<<"revised second pair details"<<endl;
	cout<<q.first<<endl;
	cout<<q.second<<endl;

	cout<<(p==q)<<endl;
	cout<<(p!=q)<<endl;
	cout<<(p>=q)<<endl;
	cout<<(p<=q)<<endl;




	return 0;
	}

___________________________________________________________________________

#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main()

{
	
	priority_queue <int> q,q1;

	q.push(10);
	q.push(40);
	q.push(20);
	q.push(60);
	q.push(2);
	q.push(7);
	q.push(70);
	q.push(90);
	q1=q;
	while(!q1.empty())
	{
		cout<<q1.top()<<endl;
		q1.pop();
		}

	cout<<"top = "<<q.top();
	q.pop();
	cout<<"\n";
	cout<<"top = "<<q.top();
	return 0;
	
	
	}

___________________________________________________________________________

#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main()

{
	queue <int> s,s1;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(100);
	cout<<s.front()<<endl;
	cout<<s.back()<<endl;

	s1=s;

	while(!s1.empty())
	{
		cout<<s1.front()<<endl;
		s1.pop();
	}
	
	return 0;
	}

_______________________________________________________________________________

#include <bits/stdc++.h>
#include <set>

using namespace std;


int main()
{
	
	set <int> s;
	s.insert(40);
	s.insert(10);
	s.insert(03);
	s.insert(20);
	s.insert(50);
	s.insert(30);
	s.insert(10);
	s.insert(70);
	
	set <int> :: iterator itr;

	for(itr=s.begin();itr!=s.end();itr++)
		cout<<*itr<<endl;

	s.erase(s.begin(),s.find(50));
	cout<<"\t\t\n";
	for(itr=s.begin();itr!=s.end();itr++)
		cout<<*itr<<endl;
		cout<<"\t\t\t\n"<<endl;
		cout<<s.size();
	return 0;
	}

_______________________________________________________________


#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	int a[] = {4,5,3,8,11,0,6,90,-3,1};

	//this function sorts the entire array
	//sort(a,a+10);
	//the following function sorts the array upto 7 elements
	//quite a cool function
	sort(a,a+7);
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<endl;
		}


		if(binary_search(a,a+10,8))
			cout<<"element present";

			else
				cout<<"element unavailable";



	return 0;
	}

_______________________________________________________________________


#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
	stack <int> s,s1;
	s.push(10);
	s.push(40);
	s.push(30);
	s.push(106);
	s.push(4);
	s.push(9);
	s.push(4);
	s.push(5);

	s1=s;

	while(!s1.empty())
	{
		cout<<s1.top()<<endl;
		s1.pop();
	}
	return 0;
	}

______________________________________________________________________________

//code to demonstrate the functioning of vectors
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()


{

vector <int> a;

	for (int i=0;i<6;i++)
	a.push_back(i);

//	for(int i=0;i<6;i++)
//		cout<<a[i]<<endl;

	vector <int> :: iterator it;
			

			for(it= a.begin();it!= a.end(); it++)
				cout<<*it<<" ";

			//	for(int x:a)
			//		cout<<x<<" ";
			//
		cout<<a.capacity()<<endl;
		
		if(a.empty())
			cout<<"vector empty"<<endl;
			cout<<"vector not empty"<<endl;


		cout<<"front="<<a.front()<<endl;
		cout<<"back="<<a.back()<<endl;
		cout<<"element at position 3 is "<<a.at(3)<<endl; 
		cout<<"size of vector = "<<a.size();
			



return 0;

}



__________________________________________________________________________

#include <bits/stdc++.h>
//#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;



int main()


{
	vector <int> A = {2,3,11,14};

	cout<<A[1];
	sort(A.begin(),A.end()); //O(nlogn)
	
	bool present = binary_search(A.begin(),A.end(),3); //true
	present = binary_search(A.begin(),A.end(),4); //false
	
	A.push_back(100);
	present = binary_search(A.begin(),A.end(),100);

	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);

	vector<int>::iterator it = lower_bound(A.begin(),A.end(),100); //>=
	vector<int>::iterator it2 = upper_bound(A.begin(),A.end(),100); //>

	cout<<*it<<" "<<*it2<<endl;
	cout<<it2 - it<<endl; //returns the total  no. of occurences.
	return 0;
	 }