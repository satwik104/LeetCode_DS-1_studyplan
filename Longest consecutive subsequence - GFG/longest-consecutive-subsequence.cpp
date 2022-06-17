// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // set<int> Hashset;
        //  int longestCount = 0;
        
        // for(int i=0;i<N;i++)
        //     Hashset.insert(arr[i]);//O(n)
        
        // for(int i=0;i<N;i++)//O(n)
        // {
        //     if(!Hashset.count(arr[i]-1))
        //     {
        //         int current_num = i;
        //         int current_count = 1;
        //         while(Hashset.count(current_num+1))//O(n)
        //         {
        //             current_num+=1;
        //             current_count+=1;
        //         }
        //         longestCount = max(longestCount,current_count);
        //     }
        // }
        // return longestCount;
         sort(arr, arr+N);
     int counter=1, max=1;
     
     for(int i=0; i<N; i++){
        if(arr[i]+1==arr[i+1]){
            counter++;
            if(counter>max)
               max=counter;
        }
        else if(arr[i]==arr[i+1])
           continue;
        else{
           counter=1;
        }
     }
     return max;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends