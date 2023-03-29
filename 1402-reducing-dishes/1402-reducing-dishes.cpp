class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        reverse(sat.begin(), sat.end());
        int n = sat.size();
        int maxSum = 0, currSum = 0, tMaxSum = 0;
        for(int i = 0; i < n; i++){
            currSum += sat[i];
            tMaxSum += currSum;
            maxSum = max(maxSum, tMaxSum);
        }
        return maxSum;
    }
};