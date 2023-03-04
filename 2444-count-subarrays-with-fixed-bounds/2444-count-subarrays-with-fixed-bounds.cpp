class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        int minFound = 0, maxFound = 0;
        int start = 0, minStart = 0, maxStart = 0;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(num < minK || num > maxK) {
                minFound = 0;
                maxFound = 0;
                start = i + 1;
            }

            if(num == minK) {
                minFound = 1;
                minStart = i;
            }

            if(num == maxK) {
                maxFound = 1;
                maxStart = i;
            }

            if(minFound && maxFound) {
                res += (min(minStart, maxStart) - start + 1);
            }
        }

        return res;
    }
};