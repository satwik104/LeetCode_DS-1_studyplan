//Approach-1 O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
			for(int i = 0; i < N; ++i) {
				for(int j = i + 1; j < N; ++j){
					if(nums[i] + nums[j] == target) {return {i, j};}
				}
			}
			return {};//if we did'nt find any thing to return 
    }
};
//Approach-2 O(n)....using Hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>&nums, int target) {
	  
	  vector<int>ans(2);
      map<int,int>mp;
      for(int i=0;i<nums.size();i++)
      {
            if(mp.find(nums[i])==mp.end())
            {
                mp[target-nums[i]] = i;
            }
            else{
                ans[0] = mp[nums[i]]; 
                ans[1] = i;
                return ans;
            }
    }
    return ans;
    }
};
