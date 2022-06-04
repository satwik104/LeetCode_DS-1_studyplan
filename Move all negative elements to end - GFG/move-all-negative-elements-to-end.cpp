// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        //aproach to place all negative to end but not in order
        /*
        int i=0,j=n-1;
        while(i<=j)
        {
            if(arr[i]<0)
            {
                swap(arr[i],arr[j]);
                j--;
            }
            else
              i++;
        }
        */
        //right approach (performing 3 array traversals)
        /*
        int help[n],k=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                help[k++]=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
                help[k++]=arr[i];
        }
        int i=0;
        for(k=0;k<n;k++)
           arr[i++]=help[k];
        */
        //best approach with two traversals using queue
        queue<int> q;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                arr[k++]=arr[i];
            }
            else
               q.push(arr[i]);
        }
        while(!q.empty())
        {
            arr[k++]=q.front();
            q.pop();
        }
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends