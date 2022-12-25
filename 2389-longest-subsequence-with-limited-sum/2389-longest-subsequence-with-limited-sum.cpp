class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for(const int q: queries) {
            ans.push_back(numOfElementLessThan(nums, q));
        }

        return ans;
    }

private:
    int numOfElementLessThan(const vector<int>& nums, int q) {
        int sum =0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > q) {
                return i;
            }
        }

        return nums.size();
    }

};