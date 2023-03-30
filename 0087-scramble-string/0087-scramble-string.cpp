class Solution {
public:
   unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        
        if(s1.length()!=s2.length())
            return false;
        int n=s1.length();
        if(n==0)return true;
        if(s1==s2)return true;
        
    string temp1 = s1;
    string temp2 = s2;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
     
    if(temp1.compare(temp2) != 0) return false;
       
        if(mp.find(s1+s2)!=mp.end())
            return mp[s1+s2];
        
        
        for(int i=1;i<=n-1;i++)   // i deotes the length of the substr
        {
if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i))) return mp[s1+s2] = true;
if(isScramble(s1.substr(0,i),s2.substr(n-i,i)) && isScramble(s1.substr(i,n-1),s2.substr(0,n-i)))return mp[s1+s2] = true;
        }
        return mp[s1+s2]=false;
    }
};