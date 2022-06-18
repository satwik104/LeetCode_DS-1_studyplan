class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        int max_len=INT_MIN;
        unordered_set<int> set;
        int l=0;
        for(int r=0;r<n;r++)
        {
            if(set.find(s[r])!=set.end())
            {
                while(l<r and set.find(s[r])!=set.end())
                {
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            max_len=max(max_len,r-l+1);
        }
        return max_len;
    }
};