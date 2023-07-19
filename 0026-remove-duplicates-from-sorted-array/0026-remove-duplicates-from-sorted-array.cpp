class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0)
        return 0;
        int i=0;
        for(int j=0; j<n; j++){
            if(nums[j] != nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};