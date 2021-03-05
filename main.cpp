//
//  main.cpp
//  towerOfHanoi
//
//  Created by Sethupathi on 11/03/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
using namespace std;

void towerOfHanoi(char a, char b, char c, int n)
{
    
    if(n==1)
        cout<<"Moving disc  "<<n<<"  from  "<<a<<"  to  "<<c<<endl;
    else
    {
        //a source b help c dest --default
        towerOfHanoi(a, c, b, n-1);


        cout<<"Moving disc  "<<n<<"  from  "<<a<<"  to  "<<c<<endl;
//        cout<<"Moving disc"<<n<<a<<"to"<<c<<endl;
        towerOfHanoi(b, a, c, n-1);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cout<<"Enter the no. of discs";
    cin>>n;
//    char a,b,c;
    towerOfHanoi('a','b','c',n);
        return 0;
}
