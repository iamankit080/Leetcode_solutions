
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flip = 0;
        int ones = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                ones++;
            } else if(ones > 0) {
                flip++;
                ones--;
            }
        }

        return flip;
    }
};