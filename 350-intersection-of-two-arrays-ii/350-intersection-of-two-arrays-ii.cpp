class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;//vector to be returned
        map<int,int> freq;
        for(int i=0;i<nums1.size();i++)//O(n)
        {
            freq[nums1[i]]++;
        }
        for(int i=0; i<nums2.size();i++)//O(m)
        {
            if(freq[nums2[i]]>0)
            {
                ans.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }
        return ans;
    }
};