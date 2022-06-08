class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        //visualize the problem on a matrix
        //each row is of differnet size so v resize each row/vector of our main ans vector
        for(int i=0;i<numRows;i++)
        {
           ans[i].resize(i+1);//v r saying ans vector to make ith vector of size i+1 inside //it
           ans[i][0]=ans[i][i]=1;//placing 1 at first and last place of a row
            
            //fill remaining middle elements
           for(int j=1;j<i;j++)
               ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
        return ans;
    }
    /*
       Time Complexity: We are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), and we are traversing through each of the cells to update it with its correct value, so Time Complexity = O(numRows2).

Space Complexity: Since we are creating a 2D array, space complexity = O(numRows2).
    */
};