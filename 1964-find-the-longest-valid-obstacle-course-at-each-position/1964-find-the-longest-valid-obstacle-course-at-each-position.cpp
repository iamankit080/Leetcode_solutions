class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> result, stk;
        for (const auto& x : obstacles) {
            const auto& i = distance(cbegin(stk), upper_bound(cbegin(stk), cend(stk), x));
            result.emplace_back(i + 1);
            if (i == size(stk)) {
                stk.emplace_back();
            }
            stk[i] = x;
        }
        return result;
    }
};