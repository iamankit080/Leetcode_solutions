class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int N = A.size();
        vector<int> ans;
        
        int i = N-1;
        //exit when both A and K are visited through
        while(i >= 0 || K > 0){
            if(i >= 0) K += A[i];
            ans.push_back(K%10);
            K/=10;
            i--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};