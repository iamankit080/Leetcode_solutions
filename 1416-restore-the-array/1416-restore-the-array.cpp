class Solution {
private:
    static const int N = 1e5 + 7;
    int dp[N];
    const int mod = 1e9 + 7;

    int f(int idx, int n, string &s, int k){

        if( idx == n ) return 1;
        if( dp[idx] != -1 ) return dp[idx];
        int ways = 0;
        long long val = 0;
        for(int i = idx; i < n; i++){
            val = val * 10 + (s[i] - '0');
            if( val >= 1 && val <= k ){
                ways += f(i + 1, n, s, k);
                ways %= mod;
            }
            else 
                break;
        }
        return dp[idx] = ways;
    }

public:
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        int totWays = f(0, (int)s.size(), s, k);
        return totWays;
    }
};