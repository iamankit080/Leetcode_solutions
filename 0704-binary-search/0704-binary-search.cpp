class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high) / 2;

        while(low <= high) {
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
            mid = (low + high) / 2;
        }
        return ans;
    }
};