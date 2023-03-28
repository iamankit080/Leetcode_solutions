
class Solution {
private:
    int dp[400];

    int newBinarySearch(int low, int k, vector<int> &days){
        int high = days.size() - 1;
        int rIdx = low;
        while( low <= high ){
            int mid = (low + high) / 2;
            if( days[mid] <= k )
                low = mid + 1, rIdx = mid;
            else
                high = mid - 1;
        }
        return rIdx;
    }

    int f(int i, int n, vector<int> &nums, vector<int> &costs){
        if( i >= n ) return 0;
        if( dp[i] != -1 ) return dp[i];
        int minCost = 1e9;
        minCost = min(minCost, costs[0] + f(newBinarySearch(i, nums[i] + 0, nums) + 1, n, nums, costs));
        minCost = min(minCost, costs[1] + f(newBinarySearch(i, nums[i] + 6, nums) + 1, n, nums, costs));
        minCost = min(minCost, costs[2] + f(newBinarySearch(i, nums[i] + 29, nums) + 1, n, nums, costs));
        return dp[i] = minCost;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        sort(days.begin(), days.end());
        int minCost = f(0, days.size(), days, costs);
        return minCost;
    }
};