#include <iostream>
#include <algorithm>
using namespace std;



int count(int *coins, int money, int n){
    int ans=0;
    while(money>0){
        int idx = upper_bound(coins,coins+n,money)-1-coins;
        cout<<coins[idx]<<" + ";
        money = money-coins[idx];
        ans++;
    }
    return ans;
}


int main(){
    
    int coins[] = {1,2,5,10,20};
    int money = 39;
    int n = sizeof(coins)/sizeof(int);
    
    cout<<count(coins,money,n);
    
    
    
    return 0;
}
