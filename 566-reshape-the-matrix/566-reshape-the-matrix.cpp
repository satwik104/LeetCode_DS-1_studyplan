//here r and c are the no. of row and column of the reshaped matrix...that is
//the matrix we need to form
//so size of given matrix should be eqaul to r*c else we need to return the given matrix
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        //no of rows in the given mat is equal to size of vector mat
        int gr = mat.size();//given row
        int gc = mat[0].size();//given col
        //if size is not same reshaping cant be done so return as it is
        if(gr*gc!=r*c)
            return mat;
        //if they are same the we perform reshaping
        vector<vector<int>> ans(r, vector<int>(c));
        // use "/" to get row no. it is divison operator
        // use "%" to get col no. it is modulus or remainder operator
        for(int i=0;i<r*c;i++)
        {
            ans[i/c][i%c] = mat[i/gc][i%gc];
        }
        return ans;
    }
};
/*
  Another possible apprach is
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
  {
      
        int gr = mat.size();//given row
        int gc = mat[0].size();//given col
        
        if(gr*gc!=r*c)
            return mat;
            
        vector<vector<int>> ans(r, vector<int>(c));
        int row=0,col=0;
        for(int i=0;i<r;i++)
        {
          for(int j=0;j<c;j++)
          {
             ans[i][j] = mat[row][col];
             col++;
             if(col==gc)
             {
                col=0;
                row++;
             }
          }
        }
        return ans;
  }
  EXPLAINATION OF FOR LOOP-
  Here we are traversing and filling the ans matrix with i and j, and using row and col to     traverse in the given matrix. once we complete a row in given matrix we change the row       with help of if brackets, where we again place the col at 0.
  TC : O(r*c)
*/