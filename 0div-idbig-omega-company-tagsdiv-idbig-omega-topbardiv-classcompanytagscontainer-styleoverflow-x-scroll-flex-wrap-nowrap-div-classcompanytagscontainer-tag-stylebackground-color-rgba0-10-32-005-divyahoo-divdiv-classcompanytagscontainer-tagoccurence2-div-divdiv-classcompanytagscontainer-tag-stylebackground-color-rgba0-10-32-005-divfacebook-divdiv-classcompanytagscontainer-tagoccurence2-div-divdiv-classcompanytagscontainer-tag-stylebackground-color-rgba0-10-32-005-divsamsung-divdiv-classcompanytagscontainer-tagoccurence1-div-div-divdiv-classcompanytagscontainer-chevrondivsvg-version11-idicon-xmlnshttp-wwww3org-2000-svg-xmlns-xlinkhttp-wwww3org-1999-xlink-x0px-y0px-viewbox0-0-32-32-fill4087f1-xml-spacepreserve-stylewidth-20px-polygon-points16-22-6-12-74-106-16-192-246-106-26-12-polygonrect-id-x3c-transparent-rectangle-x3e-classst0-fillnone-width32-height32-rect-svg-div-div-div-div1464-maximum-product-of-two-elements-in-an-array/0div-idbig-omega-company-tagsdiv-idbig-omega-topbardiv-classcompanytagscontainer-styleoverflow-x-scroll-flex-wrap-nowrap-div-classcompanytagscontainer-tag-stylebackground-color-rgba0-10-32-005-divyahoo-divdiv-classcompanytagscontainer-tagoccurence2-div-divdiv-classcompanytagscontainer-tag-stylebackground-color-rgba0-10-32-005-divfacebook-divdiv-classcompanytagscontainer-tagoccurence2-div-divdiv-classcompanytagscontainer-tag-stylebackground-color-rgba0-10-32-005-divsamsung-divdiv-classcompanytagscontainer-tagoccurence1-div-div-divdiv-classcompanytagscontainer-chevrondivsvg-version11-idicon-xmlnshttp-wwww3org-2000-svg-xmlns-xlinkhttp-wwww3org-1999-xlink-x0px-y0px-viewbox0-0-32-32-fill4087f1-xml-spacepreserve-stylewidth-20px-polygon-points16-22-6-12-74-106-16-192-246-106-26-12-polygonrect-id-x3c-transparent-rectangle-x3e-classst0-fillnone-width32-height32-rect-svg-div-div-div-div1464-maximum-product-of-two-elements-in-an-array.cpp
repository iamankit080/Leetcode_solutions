class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int maxi =(nums[i]-1)*(nums[j]-1);
                res=max(res,maxi);
            }
        }
        return res;
    }
};
//O(n^2)