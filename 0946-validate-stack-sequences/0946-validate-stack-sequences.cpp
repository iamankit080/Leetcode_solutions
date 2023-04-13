class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int m = pushed.size(), i = 0, j = 0, n = popped.size();
        while( i < n && j < m ){
            st.push(pushed[i]), ++i;
            while( j < m && !st.empty() && st.top() == popped[j] ) 
                st.pop(), ++j;
        }
        return st.empty();
    }
};