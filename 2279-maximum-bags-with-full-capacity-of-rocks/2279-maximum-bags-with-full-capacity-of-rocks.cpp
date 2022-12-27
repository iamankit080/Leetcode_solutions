class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remainig(capacity.size());
        int left = additionalRocks;
        for(int i = 0; i < capacity.size(); i++) {
            remainig[i] = capacity[i] - rocks[i];
        }

        sort(remainig.begin(), remainig.end());

        for(int i = 0; i < remainig.size(); i++) {
            if (remainig[i] > additionalRocks)
                return i;
            additionalRocks -= remainig[i];
        }

        return capacity.size();
    }
};