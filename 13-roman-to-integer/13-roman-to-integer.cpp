class Solution {
public:
    int romanToInt(string s) {
        reverse(s.begin(),s.end());
        int a[26];
        memset(a,0,sizeof(a));
        a['I'-65]=1;
        a['V'-65]=5;
        a['X'-65]=10;
        a['L'-65]=50;
        a['C'-65]=100;
        a['D'-65]=500;
        a['M'-65]=1000;
        int ans=0;
        ans+=a[s[0]-65];
        for(int i=1;i<s.size();i++){
            if(a[s[i]-65]<a[s[i-1]-65])
                ans-=a[s[i]-65];
            else
                ans+=a[s[i]-65];
        }
        return ans;   
    }
};