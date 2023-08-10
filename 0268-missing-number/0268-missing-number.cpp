class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int expsum=((n*(n+1))/2);
        int actsum=0;
        for(int i=0;i<n;i++){
            actsum=actsum+nums[i];
        }
        return(expsum-actsum); 
        
    }
};