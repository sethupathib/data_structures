//
//  main.cpp
//  a1
//
//  Created by Sethupathi on 06/11/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



int main()
{
    vector<int> v = {20,30,40,25,15,10};
    make_heap(v.begin(),v.end());
    cout<<v.front()<<endl;
    v.push_back(100);
    push_heap(v.begin(),v.end());
    cout<<v.front()<<endl;
    pop_heap(v.begin(),v.end());
    cout<<v.front()<<endl;

  return 0;
}
