
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i <= nums.size(); i++) {
            int flag = 0;
            for (int j = 0; j < nums.size(); j++) {  // Corrected loop condition
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) return i;
        }
        return -1;  // To handle the case where no missing number is found
    }
};






