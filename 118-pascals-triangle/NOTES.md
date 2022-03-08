**The pascal triangle problem has a very simple and intuitive dynamic programming approach. As the definition states, every element of a row is formed by the sum of the two numbers directly above. So, we can just apply DP and use the previously stored rows of trianlge to calculate the new rows.
**
We can just initialize the start and end elements of each row as 1 and update only the elements between them. This will make the code simpler and avoid the need of having extra checks for edge elements of each row.**
​
**Observations treat like hints**
1. If we traverse on each row with "i" starting with 0 then we can observe that each row is starting with 0.
2. We can also observe that each row end with 1 and if we code it then we can place 0 at ans[0] and ans[i] that is in row 2 ,i=1 and 1 is at 0th and 1 position...similarly in row 3, i=2 so 0 is at 0th and 2nd position that is ith position.
3. we use j in each row, and for each row j is starting from 1 (becoz 1 is already at 0th position), and j will go till i-1 (becoz 1 is at ith position).
4. we need to make vector of different size for each row so need to resize accordingly
5. Think to write code for 1st 2nd and 3rd row only.
```
class Solution {
public:
vector<vector<int>> generate(int numRows) {
vector<vector<int>> ans(numRows);
for(int i=0;i<numRows;i++)
{
ans[i].resize(i+1);// ith row has i+1 elements
ans[i][0]=ans[i][i]=1;//for each row 0th and ith is 1
//loop to calculate sum of remaining elements from previous row
for(int j=1;j<i;j++)//this will start from row 3 for i=2
ans[i][j]=ans[i-1][j] + ans[i-1][j-1];
}
return ans;
}
};
```
**Time complexity-O(n^2)**
**Space Complexity-O(n^2)**