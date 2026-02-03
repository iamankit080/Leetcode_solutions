class Solution {
    
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size(); i++){
            char c = s[i];

            if( c == '(' || c == '{' ||c == '[' ){
                st.push(c);
            }
            else{
                if(st.empty()) return false;

                char ch = st.top();
                st.pop();
                
                 if((c ==')' && ch != '(') ||
                   (c =='}' && ch != '{') ||
                   (c ==']' && ch != '[')){
                    return false;
                 } 
        }
    }
    return st.empty();
    }
};