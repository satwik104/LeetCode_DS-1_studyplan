class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //C++ provides an in-built function called next_permutation() which directly returns //the lexicographically next greater permutation of the input. but not used in interview
        /*lexicographical order is a dictionary order its just in numbers
           like in dictonary words are arranged in same way numbers are arranged 
           like 3 1 4 2 next permutation in order is 3 2 1 4 but id it was 3 1 2 4 then next 
           permutation would be 3 1 4 2 
        */
        /*
          Here one approach can be to take out all possible permutations of a give number but           that would be n! so we performe a trick.
          when we see 3 1 4 2 the next permutation that comes to our mind when we see the no.
          is 3 2 1 4 because after 1 all are in descending order means 1 is exhausted so now             we need to replace it with another number which is just bigger then 1, in this case
          it is 2 so 1 is replaced by 2 then number becomes 3 2 4 1 but now also its a
          permutation of given number but not next permutation so we have to reverse                     remaining array after 2 that is 4 1, hence ans is 3 2 1 4.
        */
        int n=nums.size(),k,l;
        for(k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
                break;//to find place k at a point from where v can start changing the order
        }
        if(k<0)
        {
            //means already we are given the last possible permutation of a number
            //so now we need to return back to first permutation by reversing the array
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(l=n-1;l>k;l--)
            {
                if(nums[k]<nums[l])
                    break;
            }
            swap(nums[k],nums[l]);
        //now we need to just reverse the array after index k
        reverse(nums.begin()+k+1,nums.end());
        }
        
            
    }
};