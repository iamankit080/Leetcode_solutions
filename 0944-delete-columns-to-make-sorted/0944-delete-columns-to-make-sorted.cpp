class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size();
        if(m==1) return 0;
        int n=strs[0].length(),cnt=0;
        for(int j=0;j<n;j++){
            for(int i=1; i<m ; i++){
                if (strs[i-1][j]>strs[i][j]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};