class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int count = 0;
        vector<int> rsum(m, 0);
        vector<int> csum(n, 0); 
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rsum[i] += mat[i][j];
                csum[j] += mat[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rsum[i] == 1 && csum[j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

//T.C=O(m*n)
//S.C=O(M+N)
    
