class Solution {
public:
    int countOdds(int low, int high) {
        int ans;
        if(low%2!=0 || high%2!=0) ans=(high-low)/2+1;
        else ans=(high-low)/2;
        return ans;
    }
};