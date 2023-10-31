class Solution {
public:
    
    int findmax(vector<int>& piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(piles[i],maxi);
        }
        return maxi;
    }
    
    
    long long calculatehr(vector<int>& piles, int hourly){
        long long totalhr=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalhr += ceil((double)(piles[i]) / (double)(hourly));
        }
        return totalhr;  
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int ans=-1;
        int high=findmax(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalhr=calculatehr(piles,mid);
            
            if(totalhr<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};