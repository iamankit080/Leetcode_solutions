class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = 0, m2 = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > m1) {
                m2 = exchange(m1, nums[i]);
            } else {
                m2 = max(m2, nums[i]);
            }
        }

        return (m1 - 1) * (m2 - 1);
    }
};


// tc=O(N),sc=O(1)
