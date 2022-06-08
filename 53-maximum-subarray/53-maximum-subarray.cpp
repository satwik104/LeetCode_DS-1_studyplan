//check the brutforce solution in notes...this one is the 3rd and best solution with linear time
//complexity
class Solution {
public:
    //approach 1 O(n^3)
   /* int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
       for(int i=0;i<nums.size();i++)
       {
           for(int j=i;j<nums.size();j++)
           {
               int window_sum =0;
               for(int k=i;k<=j;k++)
               {
                   window_sum+=nums[k];
               }
               maxsum=max(maxsum,window_sum);
           }
       }
        return maxsum;
    }*/
    //approach 3 O(n^3)
   int maxSubArray(vector<int>& nums) {
       int maxsum=INT_MIN,sum_till_now=0;
       for(int i=0;i<nums.size();i++)
       {
           sum_till_now+=nums[i];
           maxsum=max(maxsum,sum_till_now);
           if(sum_till_now<0)
               sum_till_now=0;
           
       }
       return maxsum;
   }
};