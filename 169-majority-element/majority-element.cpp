class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i : nums){
            mp[i]++;
        }

        int value = nums[0];

        for( auto it : mp){
            if(it.second > mp[value])
            value = it.first;
        }
        return value;
        
    }
};