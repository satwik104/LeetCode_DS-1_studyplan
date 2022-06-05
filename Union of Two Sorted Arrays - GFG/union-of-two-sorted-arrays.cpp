// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays.
    
    //approach 1 using hashset
    //we apply sets when ever we have problems in shich we need to avoid duplicates
    //TC- O(N+M) SC-O(N+M)
    /*
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        unordered_set<int> set;
        for(int i=0;i<n;i++)
        {
            set.insert(arr1[i]);//this will take unique/disticnt elements from arr1 in set
                                //avoiding repeat values
        }
        for(int i=0;i<m;i++)
        {
            if(set.find(arr2[i])==set.end())
              set.insert(arr2[i]);
        }
        //now we have all elements from both array which contribute in union
        vector<int> v;
        unordered_set<int>::iterator i;
        for(i=set.begin();i!=set.end();i++)
            v.push_back(*i);
        return v;
    }*/
    
    //APPROACH 2,optimizing the SC with two pointer approach
     vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0,j=0;
        vector<int> v;
        while(i<n and j<m)
        {
           if(arr1[i]<=arr2[j])
           {
               if(v.empty() || v[v.size()-1]!=arr1[i])
               v.push_back(arr1[i]);
               i++;
           }
           else
           {
               if(v.empty() || v[v.size()-1]!=arr2[j])
               v.push_back(arr2[j]);
               j++;
           }
        }
        while(i<n)
        {
            if(v.empty() || v[v.size()-1]!=arr1[i])
            v.push_back(arr1[i]);
            i++;
        }
         while(j<m)
        {
            if(v.empty() || v[v.size()-1]!=arr2[j])
            v.push_back(arr2[j]);
            j++;
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends