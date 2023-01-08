class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;
        int mx=1;
        for(int i=0;i<n-1;i++){
            unordered_map<double,int>mp;
            for(int j=i+1;j<n;j++){
                int x=points[j][0]-points[i][0], y=points[j][1]-points[i][1];
                if(x!=0) mp[(y*0.5)/x]++;
                else mp[1e9]++;
            }
            for(auto it:mp){
                mx=max(mx,it.second+1);
            }
        }
        return mx;
    }
};