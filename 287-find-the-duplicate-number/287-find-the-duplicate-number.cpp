class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //simple approach can be with hash map
        //another can be sort the array and then find adjecent easily by arr[i]==arr[i+1]
        //it will work in O(nlogn)+O(n) complexity 
        
        //another approach is using frequency array but increasing SC
        //we will simply use frequency array & initialise it with 0's,to record frequency of //each element
        //if(frequency[nums[i]]==0)
        //      frequency[nums[i]]+=1;
        //  else return nums[i];
        //Time Complexity: O(N) SC O(n)
        
        //Another trick approach only valid all numbers are positive
//in our case they are posive so ve can use it
        /*
            int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[abs(nums[i])-1]>=0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            else
                return abs(nums[i]); 
        }
        return 0;
    }
        */
        //optimal way SLOW FAST APPROACH (LINKEDLIST CYCLE METHOD)
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};