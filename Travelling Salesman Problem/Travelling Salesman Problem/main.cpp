//
//  main.cpp
//  Travelling Salesman Problem
//
//  Created by Sethupathi on 08/11/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

//#define INT_MAX 999999
int n=4;
int dp[16][4];
//adj matrix that defines the graph

int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

//if all cities have been visited
int VISITED_ALL = (1<<n)-1;

//tsp method

int tsp(int mask, int pos){
    if(mask==VISITED_ALL) return dist[pos][0];
    
    if(dp[mask][pos]!=-1) return dp[mask][pos];
    
    int ans = INT_MAX;
    for(int city=0;city<n;city++){
        int dummy_mask = 1<<city;
        if((mask&dummy_mask) == 0){
            int newAns = dist[pos][city] + tsp(mask|dummy_mask,city);
            ans = min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}



int main(int argc, const char * argv[]) {
    
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<tsp(1,0)<<endl;
   
    return 0;
}
