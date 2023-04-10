class Solution {
private:
    set<char> open = {'(', '{', '['};
    map<char, char> hsh = {{')', '('}, {']', '['}, {'}', '{'}};

public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &a : s){
            if( open.count(a) ) st.push(a);
            else{
                if( st.empty() || st.top() != hsh[a] ) return false;
                st.pop();
            }
        }
        return true && st.empty();
    }
};