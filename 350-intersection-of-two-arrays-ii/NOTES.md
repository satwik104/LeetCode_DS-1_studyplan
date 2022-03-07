**Bruteforce solution-**
placing "i" on nums1 and checking for each element of nums1 in nums2 by comparing each element of it with each element of nums2. If we got same, we replace that element with INT_MIN so that next time for same element we dont count this one.we also make an extra vector to save the matching elements
But, TC : O(n^2) SC : O(n+m)
​
**Optimized approach-**(Sorting)
In this we first sort both the vectors and then we compare the elements with each other, we they match then we push them to the  ans vector, if not then we increase the pointer of nums1 or the pointer of nums2 as per the situation.
```
class Solution {
public:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
vector<int> ans;//vector to be returned
sort(nums1.begin(),nums1.end());//O(nlogn)
sort(nums2.begin(),nums2.end());//O(mlogm)
int i=0,j=0;
while(i<nums1.size() && j<nums2.size())//if any one get false that mean no more                                                     //intersection possible,O(n) or O(m)
{
if(nums1[i]==nums2[j])
{
ans.push_back(nums1[i]);
i++;
j++;
}