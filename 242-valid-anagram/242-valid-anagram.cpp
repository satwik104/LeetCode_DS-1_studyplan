//APPROACH 1(BRUTEFORCE...time=76ms)
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.length()!=t.length())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        if(s!=t)
            return false;
        return true;
    }
};
*/
//APPROACH 2(HASHMAP....time 36ms)
//we can make a hashmap in which value increase by 1 for each key from s and decrease by 1 for //each key from t...at end if all values are 0 then return true
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int n=s.length();
        unordered_map<char,int> map;
        for(int i=0;i<n;i++)
        {
            map[s[i]]++;
            map[t[i]]--;
        }
        for(auto count : map)
            if(count.second)
                return false;
        return true;
        
    }
};
*/

/*Since the problem statement says that "the string contains only lowercase alphabets", we can simply use an array to simulate the unordered_map and speed up the code. The following implementation takes 12 ms.*/
//APPROACH 3(TIME=12ms)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};
