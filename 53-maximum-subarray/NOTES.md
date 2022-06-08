******************BRUTFORCE-O(n^3)*********************
​
// Including climits, which allows for usage of INT_MIN constant in C++
#include <climits>
​
class Solution {
public:
int maxContiguousSubarraySum(vector<int>& nums) {
int n = nums.size();
int maximumSubArraySum = INT_MIN;
/*
We will use these outer 2 for loops to investigate all
windows of the array.
We plant at each 'left' value and explore every
'right' value from that 'left' planting.
These are our bounds for the window we will investigate.
*/
for (int left = 0; left < n; left++) {
for (int right = left; right < n; right++) {
// Let's investigate this window
int windowSum = 0;
// Add all items in the window
for (int k = left; k <= right; k++) {
windowSum += nums[k];
}
// Did we beat the best sum seen so far?
maximumSubArraySum = max(maximumSubArraySum, windowSum);
}
}
return maximumSubArraySum;
}
};
​
*********************************OPTIMIZED-O(n^2)*********************
​
// Including climits, which allows for usage of INT_MIN constant in C++