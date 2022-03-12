class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    int tp=0,n=nums.size();//total pairs
//there are two cases...k==0 or k!= 0, if k==0 then we need to find same no. but on different index..so simply if freq of a no.
    //is more then 1 then we will increase the tp
    for(int i=0; i<n; i++)
        map[nums[i]]++;
    if(k==0)
    {
        for(int i=0;i<n;i++)
        {
            if(map[nums[i]]>1)
              {
                tp++;
                map[nums[i]+k]=0;
               }
        }
        return tp;
    }
    //if k!=0
    else
    {
        for(int i=0;i<n;i++)
        {
            if(map[nums[i]+k])
            {
                tp++;
                map[nums[i]+k]=0;
            }
        }
        return tp;
    }
  }
};
    /*
        //APPROACH IF WE DONT WANT ONLY UNIQUE PAIRS
int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int> map;
    int total_pair=0;
    //now we need to focus on two numbersfor a no. at arr[i],,these are the complements of arr[i]
    //1. arr[i]+k
    //2. arr[i]-k
    for(int i=0; i<n; i++)
    {
        total_pair+=map[arr[i]+k];
        if(k!=0)
        {
            total_pair+=map[arr[i]-k];
        }
    
        map[arr[i]]++;
    }
    return total_pair;
}
    */