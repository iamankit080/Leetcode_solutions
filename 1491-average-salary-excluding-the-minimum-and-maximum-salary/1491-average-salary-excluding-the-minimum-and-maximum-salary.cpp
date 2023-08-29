class Solution {
public:
    double average(vector<int>& s) {
        double ans =0;
        int mini = 1e8 , maxi=0;
        for(int i =0;i<s.size();i++){
            mini = min(mini , s[i]);
            maxi = max(maxi,s[i]);
            ans +=s[i];
        }
        ans = ans - mini - maxi;
        ans = ans/(s.size()-2);
        return ans;
    }
};