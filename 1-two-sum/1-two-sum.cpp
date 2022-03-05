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
      map<int,int>mp;//here key will be the number and value will be its index
      for(int i=0;i<nums.size();i++)
      {
            if(mp.find(target-nums[i])!=mp.end())
            {
		    //fill the right indexex in ans vector
                ans[0] = mp[target-nums[i]]; //value of it will be its index
                ans[1] = i;
                return ans;
            }
	      //if we didint find it pair in hashtable we simply put that number in table for future searching
            else{
                mp[nums[i]] = i;//we are saving its index as its value....because we have to return index...not the numbers
            }
    }
    return ans;
    }
};
