class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>map;
        for(int i=0;i<s.size();i++)
        {
            map[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(map[s[i]]==1)
                return i;
        }
        return -1;
    }
};
//this is one approach another can be more optimized if we use map<char,pair<int,int>>
//this way we dont need to traverse whole string again