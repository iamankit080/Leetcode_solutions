int dp[1001][2001];

class Solution {
private:

    int memo(int i, int n, int k, vector<vector<int>> &piles){
        if( i == n || k == 0 ) return 0;
        int &ans = dp[i][k];
        if( ans != -1 ) return ans;
        int maxCoins = memo(i + 1, n, k, piles);
        int m = piles[i].size();
        int preSum = 0;
        for(int j = 0; j < m; j++){
            preSum += piles[i][j];
            if( k - (j + 1) >= 0 ){
                int currCoins = preSum + memo(i + 1, n, k - (j + 1), piles);
                maxCoins = max(maxCoins, currCoins);
            }
        }
        ans = maxCoins;
        return maxCoins;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        int maxCoins = memo(0, n, k, piles);
        return maxCoins;
    }
};