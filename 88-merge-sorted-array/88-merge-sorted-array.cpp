class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //bruteforce
        //copy all elements of nums2 in nums1 
        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        //now sort it
       sort(nums1.begin(), nums1.end());
    }
    /*
      TC :0(m+n)log(m+n) [for sorting the array] + 0(n)[for copying the elements of nums2 to           nums1]
      So, overall TC : 0(m+n) log(m+n)
      SC: 0(1)
    */
};