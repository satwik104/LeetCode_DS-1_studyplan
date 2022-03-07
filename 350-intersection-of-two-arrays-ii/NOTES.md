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
else if(nums1[i]<nums2[j])
i++;
else
j++;
}
return ans;
}
};
```
TC : O(nlogn) + O(mlogm) + { O(n) or O(m) }
SC : O(n+m)
​
**Hashmap approach**
In this appraoach we simply take frequency of nums1 elements in freq map and then we check them with nums2 if any frequency for an element of nums2 is more then 0 in the map that means the element is in both the vectors, hence we include it in the ans, and also reduce its frequency in the map by 1, so that if we again encounter it in nums2 we can make decision accordingly.
```
class Solution {
public:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
vector<int> ans;//vector to be returned
map<int,int> freq;
for(int i=0;i<nums1.size();i++)//O(n)
{
freq[nums1[i]]++;
}