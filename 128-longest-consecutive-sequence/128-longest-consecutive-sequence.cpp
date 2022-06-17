class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //bruteforce O(nlogn)+O(n);
        /*
        sort(nums.begin(),nums.end());
        int n=nums.size(),max_count=1,count=1,prev=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==prev+1) count++;
            else
                count=1;
            prev=nums[i];
            max_count = max(max_count,count);
        }
        return max_count;
        */
        //optimal way O(3n) TC 
        set<int> Hashset;
         int longestCount = 0;
        
        for(int i : nums)
            Hashset.insert(i);//O(n)
        
        for(int i:nums)//O(n)
        {
            if(!Hashset.count(i-1))
            {
                int current_num = i;
                int current_count = 1;
                while(Hashset.count(current_num+1))//O(n)
                {
                    current_num+=1;
                    current_count+=1;
                }
                longestCount = max(longestCount,current_count);
            }
        }
        return longestCount;
    }
};