// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

/*

//APPROACH 1 complexity is O(nlogn) so we rejected it
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr,arr+r+1);
        return arr[k-1];
    }
};
*/
//APPROACH 2 STILL FAILING SOME CASES
//using sets as it is mentioned that all elements are distinct
//set use O(logn) complexity as its working on bst
/*
class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        set<int> s(arr,arr+r+1);
        //now make an iterator for set
        set<int>::iterator i = s.begin();//this will point i to first element of sets
        advance(i,k-1);
        return *i;
    }*/
    //APPROACH 3
    //using Max Heap TC: O(n+klogn)
    //implementing max heap by priority queue
    class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> maxh;
        for(int i=0;i<r+1;i++)
        {
            maxh.push(arr[i]);
            if(maxh.size()>k)
               maxh.pop();
        }
        return maxh.top();
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends