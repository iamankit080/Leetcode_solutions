class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char, int> pcount;
        for(char c: p){
            if(pcount.find(c) == pcount.end()){
                pcount[c] = 1;
            }else{
                pcount[c]++;
            }
        }
        
        map<char, int> wcount; //the occurence of chars in a sliding window
        int start = 0, end = 0, match = 0;
        
        while(end < s.size()){
            char c1 = s[end];
            if(pcount.find(c1) != pcount.end()){
                //update wcount
                if(wcount.find(c1) == wcount.end()){
                    wcount[c1] = 1;
                }else{
                    wcount[c1]++;
                }
                //increase 'match' when the occurences match each other
                if(pcount[c1] == wcount[c1])match++;
            }
            
            //find start while 'match' is the correct number
            while(match == pcount.size()){
                //only when the matched kind of char's count are right,
                // and the total matched count are right,
                // we find an valid start
                if(end - start + 1 == p.size()){
                    ans.push_back(start);
                }
                
                //discard s[start], update sliding window and 'match'
                char c2 = s[start];
                if(pcount.find(c2) != pcount.end()){
                    wcount[c2]--;
                    if(wcount[c2] < pcount[c2])match--;
                }
                start++;
            }
        
            end++;
        }
        
        return ans;
    }
};