class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int vcount=0;
        for(int i=0;i<k;++i){
            if(vowels.find(s[i]) !=vowels.end()) vcount++;
            
        }
        int l=0,r=k-1;
        int mvc= vcount;
        while(r<s.length()-1){
            if(vowels.find(s[l]) !=vowels.end()) vcount--;
            l++;
            r++;
            if(vowels.find(s[r]) !=vowels.end()) vcount++;
            mvc= max(mvc, vcount);
        } 
        return mvc;
     }
};