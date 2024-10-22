class Solution {
public:
    bool checkRecord(string s) {
        int a_count = 0, l_count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') a_count++;
            if (s[i] == 'L') l_count++;
            else l_count = 0;
            if (a_count >= 2 || l_count > 2) return false;
        }
        return true;
    }
};
