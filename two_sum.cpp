/*Good Problem --
Three approaches
1. O(N^2) -- Brute Force
2. O(N.log(N)) -- 2 Pointer
3. O(N) -- Unordered Set
*/
    //2 Pointer technique

bool solve(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums.size()-1;
    while(low<high){
        int sum = nums[low] + nums[high];
        if(sum==k){
            return true;
        }
        else if(sum<k) low++;
        else high--;
    }
    return false;

} 

// best approach O(n)
bool solve(vector<int>& nums, int k) {
  //using set
  unordered_set<int> s;
  for(int  i:nums){
      if(s.find(k-i)!=s.end()){
          return true;}
          s.insert(i);
      
  }
  return false;

}

