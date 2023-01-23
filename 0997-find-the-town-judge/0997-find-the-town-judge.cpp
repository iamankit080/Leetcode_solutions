
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n + 1);

        for(vector<int> a : trust) {
            count[a[0]]--;
            count[a[1]]++;
        }

        for (int i = 1; i < n + 1; ++i)
            if (count[i] == n - 1)
                return i;

        return -1;
    }
};