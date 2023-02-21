class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sol;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto i: mp) {
            if(i.second == 1) sol = i.first;
        }

        return sol;
    }
};