/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size(),i;
        for(i=0; i<row; i++)
        {
            if(matrix[i][col-1]>=target)//col-1 will be the last element of each row
                break;
        }
        if(matrix[i][col-1]==target)
            return true;
        //now we search target in these rows by traVERSING TO ALL ELEMENTS
        for(int j=0; j<=i; j++)
        {
            for(int k=0;k<col;k++)
            {
                if(matrix[j][k]==target)
                    return true;
            }
        }
        return false;
    }
};*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size()-1;
        int m = a[0].size()-1;
        
        //first search row using binary search
        //condition of target in that row is if a[i][0] <= target >= a[i][m]
        //then 'i'th row is correct row
        
        int row = -1;
        int start = 0, end = n;      
        while(start <= end)
        {
            int mid = (start - end) / 2 + end;
            if(a[mid][0] <= target && a[mid][m] >= target) {
                row = mid;
                break;
            }
            
            if(a[mid][0] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        if(row == -1) {
            //if no such row present this means element not exist
            return false;
        }
        
        //now search element in that row using Binary search
        start = 0, end = m;      
        while(start <= end)
        {
            int mid = (start - end) / 2 + end;
            
            if(a[row][mid] == target) {
                return true;
            }
            
            if(a[row][mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return false;
    }
};