class Solution {
private:
    int dp[201][201];

    int func(int i, int j, int n, int m, vector<vector<int>> &grid){
        if( i == n - 1 && j == m - 1 ) return grid[i][j];
        if( dp[i][j] != -1 )
            return dp[i][j];
        int minSum = 1e9;
        if( j + 1 < m )
            minSum = min(minSum, grid[i][j] + func(i, j + 1, n, m, grid));
        if( i + 1 < n )
            minSum = min(minSum, grid[i][j] + func(i + 1, j, n, m, grid));
        dp[i][j] = minSum;
        return minSum;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int minSum = func(0, 0, grid.size(), grid[0].size(), grid);
        return minSum;
    }
};