class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(),a=0,b=0;
        bool found = false;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    a=i;
                    b=j;
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
         vector<int> ans;
         ans.push_back(a);
         ans.push_back(b);
         return ans;
    }
};