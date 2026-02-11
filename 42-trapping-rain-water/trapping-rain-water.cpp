class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        

        for(int i=0;i<n;i++){

            int lmax=height[i];
            for(int j=0;j<i;j++){ //finding left max height 0 to i-1 for i
                lmax=max(height[j],lmax);
            }

            int rmax=height[i];
            for(int j=i;j<n;j++){ //finding rhight max height from i to n-1 for i
                rmax=max(height[j],rmax);
            }
            total = total + (min(lmax,rmax)-height[i]);
        }
        return total;
    }
};