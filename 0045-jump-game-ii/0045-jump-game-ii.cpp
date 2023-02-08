class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int current=0;
        int maxmdis=0;

        int n= nums.size();
        for(int i=0; i<n-1; i++){
            maxmdis = max(maxmdis , nums[i] +i);
            if(i==current)
            {
                current= maxmdis;
                jump++;
            }
        }
        return jump;
    }
};