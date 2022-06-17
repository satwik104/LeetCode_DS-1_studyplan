// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        //bruteforce
         vector<int> arr(r*c,0);
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               //converting 2 D to 1 D
               int idx=j+(i*c); 
               arr[idx]=matrix[i][j];
           }
       }
       sort(arr.begin(),arr.end());
       return arr[arr.size()/2];
      
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends