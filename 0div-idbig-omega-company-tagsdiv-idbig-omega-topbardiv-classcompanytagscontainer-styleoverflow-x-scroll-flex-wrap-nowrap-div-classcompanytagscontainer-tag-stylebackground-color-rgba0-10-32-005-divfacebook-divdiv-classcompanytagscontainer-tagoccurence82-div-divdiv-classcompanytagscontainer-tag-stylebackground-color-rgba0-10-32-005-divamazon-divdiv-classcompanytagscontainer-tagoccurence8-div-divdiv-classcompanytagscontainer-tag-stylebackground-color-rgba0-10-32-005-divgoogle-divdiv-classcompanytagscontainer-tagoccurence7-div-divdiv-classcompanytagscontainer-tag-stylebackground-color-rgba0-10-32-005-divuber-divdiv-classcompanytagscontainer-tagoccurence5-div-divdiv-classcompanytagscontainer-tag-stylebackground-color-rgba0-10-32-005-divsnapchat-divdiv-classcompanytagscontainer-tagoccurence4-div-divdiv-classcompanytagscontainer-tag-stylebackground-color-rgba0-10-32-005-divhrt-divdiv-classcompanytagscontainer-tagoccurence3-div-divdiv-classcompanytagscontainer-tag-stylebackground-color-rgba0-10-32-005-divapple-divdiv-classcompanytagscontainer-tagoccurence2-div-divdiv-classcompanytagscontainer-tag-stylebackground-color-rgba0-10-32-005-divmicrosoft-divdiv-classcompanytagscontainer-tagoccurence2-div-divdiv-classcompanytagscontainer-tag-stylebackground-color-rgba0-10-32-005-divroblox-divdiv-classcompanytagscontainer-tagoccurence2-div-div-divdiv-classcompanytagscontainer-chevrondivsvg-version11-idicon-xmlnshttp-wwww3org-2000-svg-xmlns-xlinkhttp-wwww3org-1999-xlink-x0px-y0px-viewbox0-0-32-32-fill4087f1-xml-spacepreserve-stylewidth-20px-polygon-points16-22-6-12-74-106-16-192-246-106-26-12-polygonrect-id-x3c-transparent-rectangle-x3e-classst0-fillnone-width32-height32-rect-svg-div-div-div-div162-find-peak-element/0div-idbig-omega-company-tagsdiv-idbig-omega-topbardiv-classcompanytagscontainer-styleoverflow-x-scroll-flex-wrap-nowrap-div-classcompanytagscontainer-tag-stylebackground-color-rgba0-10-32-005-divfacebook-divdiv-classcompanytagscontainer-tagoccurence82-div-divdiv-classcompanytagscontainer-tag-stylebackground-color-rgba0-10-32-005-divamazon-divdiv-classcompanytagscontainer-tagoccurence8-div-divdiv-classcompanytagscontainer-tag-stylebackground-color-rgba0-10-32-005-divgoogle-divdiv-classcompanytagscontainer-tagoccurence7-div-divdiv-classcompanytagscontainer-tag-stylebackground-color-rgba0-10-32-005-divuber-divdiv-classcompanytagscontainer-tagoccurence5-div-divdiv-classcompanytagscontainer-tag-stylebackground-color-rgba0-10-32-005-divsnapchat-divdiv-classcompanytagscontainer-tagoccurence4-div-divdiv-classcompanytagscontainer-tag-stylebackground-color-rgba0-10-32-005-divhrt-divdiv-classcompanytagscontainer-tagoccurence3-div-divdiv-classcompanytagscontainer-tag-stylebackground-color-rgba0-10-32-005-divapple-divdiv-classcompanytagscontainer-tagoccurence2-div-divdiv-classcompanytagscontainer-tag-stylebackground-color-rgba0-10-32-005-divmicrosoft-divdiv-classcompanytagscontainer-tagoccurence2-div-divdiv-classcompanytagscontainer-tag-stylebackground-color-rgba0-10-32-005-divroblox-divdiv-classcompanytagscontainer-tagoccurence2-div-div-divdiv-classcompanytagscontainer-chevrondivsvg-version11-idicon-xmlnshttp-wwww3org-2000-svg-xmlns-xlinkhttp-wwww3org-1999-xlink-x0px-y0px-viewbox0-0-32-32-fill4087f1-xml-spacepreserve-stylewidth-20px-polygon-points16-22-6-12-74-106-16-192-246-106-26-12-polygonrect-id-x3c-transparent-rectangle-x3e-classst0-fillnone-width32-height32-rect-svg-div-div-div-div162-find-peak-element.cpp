class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxi=INT_MIN;
        int index=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=max(nums[i],maxi);
                 index=i;
            }
        }
        return index;
        
    }
};