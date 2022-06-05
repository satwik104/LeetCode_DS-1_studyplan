// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
     int getMinDiff(int arr[], int n, int k) {
        /*in this question each element have two options either to add k or substract k
        analysing each case will be a 2^n work so we need to approach it in following way*/
        if(n==1) return 0;//for sake of interview
        sort(arr,arr+n);//to place min and max hights at first and last
        int diff = arr[n-1]-arr[0];//this is our current diff between max and min hights
        
        int mi,ma;//min and max
        /*now its not necessary that only first and last best candidates for the operations 
          and we have to work on them only, it can be possible that other elements between them
          also contribute so what we do now is
          we will try to find that is their any other possible max element other then last one
          by adding k to all except the last one and substracting k from last one.
          
          similarly, we will figure out any other possible element for min hight other then first
          by adding k to first and substracting k from others
          
          at the end we will be having right min and max hights for making ans
          **REMEMBER TO SKIP THE NUMBER WHICH CAN GET -IVE WHEN SUBSTRACTING K**
        */
        for(int i=1;i<n;i++)
        {
           // if((arr[i]-k)<0) continue;
            ma = max(arr[i-1]+k,arr[n-1]-k);
            mi = min(arr[0]+k,arr[i]-k);
            
            diff = min(diff,ma-mi);
        }
        return diff;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends