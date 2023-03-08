class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1, right = 1000000000;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (isPossible(piles, middle , h)) {
                // Koko eats too fast.
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        return left;
    }

private:
    bool isPossible(vector<int> &piles, int k, int h) {
        int time = 0;
        for (auto &bananas : piles) {
            time = time + bananas / k;
            if (bananas % k) {
                ++time;
            }
        }
        return time <= h;
    }
};