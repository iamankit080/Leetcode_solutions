class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        for (size_t i = 0; i < scores.size(); ++i) {
            players.emplace_back(ages[i], scores[i]);
        }
        sort(begin(players), end(players));
        vector<int> dp(size(scores));
        int result = 0;
        for (int i = 0; i < size(players); ++i) {
            dp[i] = players[i].second;
            for (int j = 0; j < i; ++j) {
                if (players[j].second <= players[i].second) {
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};