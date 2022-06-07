class Solution {
public:
    //APPROACH 1 BRUTEFORCE
    //Basic idea is to convrt all elements to -1 of the place where we find zero so that it do  //not disturb other row and col when further we find any other location for 0 (assuming all //elements are positivee in matrix)
    
   /*void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    int k=i-1;//for going each row and changing number to -1
                    while(k>=0)
                    {
                        if(matrix[k][j]!=0)
                            matrix[k][j]=-1;
                        k--;
                    }
                    k=i+1;
                    while(k<m)
                    {
                        if(matrix[k][j]!=0)
                            matrix[k][j]=-1;
                        k++;
                    }
                    k=j-1;
                    while(k>=0)
                    {
                        if(matrix[i][k]!=0)
                            matrix[i][k]=-1;
                        k--;
                    }
                    k=j+1;
                    while(k<n)
                    {
                        if(matrix[i][k]!=0)
                            matrix[i][k]=-1;
                        k++;
                    }
                }
            }
        }
        //now we have all locations where we need to replace -1 to 0
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(matrix[i][j]==-1)
                    matrix[i][j]=0;
        }
    }*/
    
    ///APPROACH 2 BETTER FOR TIME COMPLEXITY
   //Basilly What we can do is we can use a dummy array insted of traversing each row andcol
    
//Approach:Take two dummy array one of size of row and other of size of column.Now traverse through the array.If matrix[i][j]==0 then set dummy1[i]=0(for row) and dummy2[j]=0(for column).Now traverse through the array again and if dummy1[i]==0  || dummy2[j]==0 then arr[i][j]=0,else continue.
    /*
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.size();
        vector<int> dummy1(m,-1),dummy2(n,-1);
        //now traverse on matrix;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    dummy1[i]=0;
                    dummy2[j]=0;
                }
            }
        }
        //now traverse on dummy vectors to place zero in matrix
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(dummy1[i]==0 || dummy2[j]==0)
                    matrix[i][j]=0;
        }
        Time Complexity: O(N*M + N*M)
        Space Complexity: O(n)+O(m)
    }*/
    
    //Approach 3 better space complexity
     void setZeroes(vector < vector < int >> & matrix) {
  int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    //checking if 0 is present in the 0th column or not
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  //traversing in the reverse direction and
  //checking if the row or col has 0 or not
  //and setting values of matrix accordingly.
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols - 1; j >= 1; j--) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (col0 == 0) {
      matrix[i][0] = 0;
    }

  }

}
};