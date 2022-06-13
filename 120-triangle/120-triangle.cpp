class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        vector<int> row;
        for(int i=1;i<len;i++){
            row=triangle[i-1];
            for(int j=0;j<(i+1);j++){
                if(j==0)
                    triangle[i][j]+=row[j];
                else if(j==i)
                    triangle[i][j]+=row[j-1];
                else
                    triangle[i][j]+=min(row[j-1], row[j]);
            }
        }
        row = triangle.back();
        return *min_element(row.begin(), row.end());
    }
};