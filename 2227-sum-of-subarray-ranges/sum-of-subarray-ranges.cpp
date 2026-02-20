class Solution {

    
    vector<int> findnse(vector<int> &arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i=n-1; i>=0; i--){
            int curr_ele = arr[i];

            while(!st.empty() && arr[st.top()]>= arr[i]){
                st.pop();
            }

            if(!st.empty()){
                ans[i]=st.top();
            }
            else ans[i]=n;
            st.push(i);
        }
        return ans;
    }

    vector<int> findnge(vector<int> &arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i=n-1; i>=0; i--){
            int curr_ele = arr[i];

            while(!st.empty() && arr[st.top()]<= arr[i]){
                st.pop();
            }

            if(!st.empty()){
                ans[i]=st.top();
            }
            else ans[i]=n;
            st.push(i);
        }
        return ans;
    }

    vector<int> findpsee(vector<int> &arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            int curr_ele = arr[i];

            while(!st.empty() && arr[st.top()]> arr[i]){ //storing index not value
                st.pop();
            }

            if(!st.empty()){
                ans[i]=st.top();
            }
            else ans[i]=-1;
            st.push(i);
        }
        return ans;
    }

    
    vector<int> findpgee(vector<int> &arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            int curr_ele = arr[i];

            while(!st.empty() && arr[st.top()] < arr[i]){ //storing index not value
                st.pop();
            }

            if(!st.empty()){
                ans[i]=st.top();
            }
            else ans[i]=-1;
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans=0;
        
        vector<int>nse = findnse(arr);
        vector<int>psee = findpsee(arr);

        for(int i=0;i<n;i++){
            int left = i-psee[i];
            int right = nse[i] - i;

            long long contribution = (( left * right * 1LL)* arr[i]);
            ans = (ans + contribution);

        }
        return ans;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        long long ans=0;
        
        vector<int>nse = findnge(arr);
        vector<int>psee = findpgee(arr);

        for(int i=0;i<n;i++){
            int left = i-psee[i];
            int right = nse[i] - i;

            long long contribution = (( left * right * 1LL) * arr[i]);
            ans = (ans + contribution);

        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {

        long long result = (sumSubarrayMax(nums)-sumSubarrayMins(nums));

        return result;
    }
};