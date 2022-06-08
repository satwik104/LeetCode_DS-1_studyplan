class Solution {
public:
    void sortColors(vector<int>& nums) {
        //approach 1 - library sort function
        //approach 2 - keeping count of numbers then arranging them accordingly 
        //Time Complexity: O(N) + O(N) SC = O(1)
        //approach 3 (best SC: O(1),TC:O(N))
        //we use dutch national flag algo here
        //we assume that all numbers on left of low will be 0 elements between low to mid and //mid to high will be 1 and elements on right of high will be 2
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high)//mid will be traversing the array for us
            //if it find a 0 it will move ahed with low after swapping
            //if it faces 2 then it will swap with high and reduce high
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[low++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
    }
};