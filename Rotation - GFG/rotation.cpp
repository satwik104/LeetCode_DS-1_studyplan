// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    //approach 1
	   /* int x= *min_element(arr,arr+n);//TC: O(n)
	    int count = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]==x)
	        {
	            break;
	        }
	        count++;
	    }
	    return count;
	}*/
	//APPROACH 2
	// We basically find index of minimum element
	//TC: O(n) SC: O(1)
	
    int min = arr[0], min_index = 0;
    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
    
    
    
    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends