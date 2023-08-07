class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int n=s.length();
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                depth++;
            else if(s[i]==')')
                depth--;
            res=max(res,depth);
        }
        return res;
        
    }
};