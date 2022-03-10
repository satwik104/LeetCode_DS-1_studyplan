class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length())
            return false;
        unordered_map<char,int> map;
        for(int i=0;i<magazine.length();i++)
            map[magazine[i]]++;
        for(int i=0;i<ransomNote.length();i++)
        {
            if(map[ransomNote[i]])
                map[ransomNote[i]]--;
            else
                return false;
        }
        return true;
    }
};
//The complexity is O(N), N is the length of magazine.