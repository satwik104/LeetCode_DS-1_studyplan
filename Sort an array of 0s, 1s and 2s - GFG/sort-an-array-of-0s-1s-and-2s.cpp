// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //DUTCH NATIOANAL FLAG PROBLEM
    //we use three pointer approach here
    //we just place 0 and 2 at right position and 1 will be automatically placed at right position
    //O(n) single iteration of array
    void sort012(int a[], int n)
    {
        /*
        int i=0,for_zero=0,for_two=n-1;
        while(i<=for_two)
        {
              if(a[i]==0)
            {
                swap(a[i],a[for_zero]);
                i++; for_zero++;
            }
            if(a[i]==2)
            {
                swap(a[i],a[for_two]);
                for_two--;
            }
            else
              i++;
        }*/
        int count0 = 0,count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++){      
        if(a[i] == 0){
            count0++;
        }
        if(a[i] == 1){    
            count1++;
        }  
    }
    
    for(int i=0;i<count0;i++){    
        a[i]=0;
    }
    int temp = count0 + count1;
     for(int i=count0;i<temp;i++){    
        a[i]=1;
    }
     for(int i=temp;i<n;i++){    
        a[i]=2;
    }
    }
    
};

//APPROACH 2
//O(n) approach but two traversals on the array
/*void sort012(int *arr, int n)
{
     int count0 = 0,count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++){      
        if(arr[i] == 0){
            count0++;
        }
        if(arr[i] == 1){    
            count1++;
        }  
    }
    
    for(int i=0;i<count0;i++){    
        arr[i]=0;
    }
    int temp = count0 + count1;
     for(int i=count0;i<temp;i++){    
        arr[i]=1;
    }
     for(int i=temp;i<n;i++){    
        arr[i]=2;
    }
}
*/
//APPROACH 3 o(nlogn)
//JUST SORT THE ARRAY AND ITS DONE by calling sort(a,a+n);

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends