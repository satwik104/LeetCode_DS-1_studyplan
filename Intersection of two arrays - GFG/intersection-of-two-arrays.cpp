// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    
    //approach 1 USING HASHSET
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_set<int> set1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            set1.insert(a[i]);
        }
        for(int i=0;i<m;i++)
        {
             if(set1.find(b[i])!=set1.end())
             count++;
             set1.erase(b[i]);
        }
        return count;
    }
   /* //APPROACH 2 
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
       
    }*/
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends