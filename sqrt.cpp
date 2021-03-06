#include <iostream>
using namespace std;


int sq_root(int n){
    
    int s=0;
    int e=n;
    float ans;
    
    while(s<=e){
        int mid = (s+e)>>1;
        if(mid*mid == n){
            return mid;
        }
        if(mid*mid <n){
            ans =mid;
            s = mid+1;
        }
        else e =mid-1;
    }
    
    
    return ans;
}
int main() {
	int n;
	cin>>n;
	cout<<sq_root(n);
	return 0;
}
