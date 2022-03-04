//check the brutforce solution in notes...this one is the 3rd and best solution with linear time
//complexity
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;//initially
        int max_sum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            max_sum=max(sum,max_sum);
            if(sum<0)
                sum=0;//make it 0,becoz we dont want to add a -ive no. to next no.
            //this is the base of kadane's algo...we dont take sum of subarray if it is -ive
        }
        return max_sum;
    }
};