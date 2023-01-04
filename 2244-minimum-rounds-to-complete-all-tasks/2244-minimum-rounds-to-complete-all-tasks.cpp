class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int ele:tasks) mp[ele]++;
        int cnt=0;
        for(auto it:mp){
            if(it.second<2) return -1;
            else if (it.second%3==0) cnt+=(it.second)/3;
        else cnt+=((it.second)/3)+1;
        }
       return cnt;
        
    }
};