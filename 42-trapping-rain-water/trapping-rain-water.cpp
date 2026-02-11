class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        vector<int>prefixmax(n);
        vector<int>suffixmax(n);

        prefixmax[0] = height[0];
        suffixmax[n-1] = height[n-1];

        for(int i=1;i<n;i++){
            prefixmax[i] = max(prefixmax[i-1], height[i]);
        }
        
        for(int i=n-2; i>0; i--){
            suffixmax[i] = max(suffixmax[i+1], height[i]);
        }

        for(int i=0;i<n;i++){
            if(height[i]<prefixmax[i] && height[i]<suffixmax[i]){
                total = total + (min(prefixmax[i], suffixmax[i])-height[i]);
            }
        }
        return total;        
    }
};