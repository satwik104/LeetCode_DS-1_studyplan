class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //a simple solution can be using Hash maps but its not optimal
        //it will be in TC of O(nlogn) and SC of O(n)
        /*********************OPTIMAL APPROACH (Moore’s Voting Algorithm)************/
        int n=nums.size();
        int count=0,element=0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
                element=nums[i];
            if(element==nums[i])
                count++;
            else
                count--;
        }
        return element;
        
    }
};