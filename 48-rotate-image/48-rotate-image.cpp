class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        /*
            If must solve in-place then
- Swap corresponding values
- Store one or more different values in the same pointer
        */
        
        //brute force- by using an extra matrix then shifting whole row of orignal to
        //last coloumn of extra matrix then second row to last second col and so on
        //TC: O(N*N)
        //SC: O(N*N)
       /* int n = matrix.size();
        vector<vector<int>> rotated(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                rotated[j][n-i-1]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=rotated[i][j];
            }
        }*/
        
        /*
             Solution 2: Optimized approach
              Intuition: By observation, we see that the first column of the original                     matrix is the reverse of the first row of the rotated matrix, so that’s why                 we transpose the matrix and then reverse each row, and since we are making                   changes in the matrix itself space complexity gets reduced to O(1).
              Time Complexity: O(N*N) + O(N*N).One O(N*N) for transposing the matrix and the               other for reversing the matrix.
              Space Complexity: O(1).
        */
        //transposing means changing row to col and col to rows
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[j][i],matrix[i][j]);//for transpose
            }
        }
        //reversing each row of the matrix
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());//reversing ith inside vector 
        }
        
    }
};