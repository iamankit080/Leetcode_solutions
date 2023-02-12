class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };
        vector<vector<int>> adj(size(roads) + 1);
        for (const auto& r : roads) {
            adj[r[0]].emplace_back(r[1]);
            adj[r[1]].emplace_back(r[0]);
        }
        int64_t result = 0;
        const function<int(int, int, int)> dfs = [&](int u, int p, int d) {
            int cnt = 1;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                cnt += dfs(v, u, d + 1);
            }
            if (d) {
                result += ceil_divide(cnt, seats);
            }
            return cnt;
        };
        dfs(0, -1, 0);
        return result;
    }
};