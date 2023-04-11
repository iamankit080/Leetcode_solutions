class Solution {
public:
    string removeStars(string s) {
        string resultantString;
        for(auto &a : s){
            if( a == '*' ){
                if( !resultantString.empty() ) resultantString.pop_back();
            }
            else resultantString += a;
        }
        return resultantString;
    }
};