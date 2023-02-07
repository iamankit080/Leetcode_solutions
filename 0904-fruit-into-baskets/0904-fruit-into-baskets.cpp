class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last_fruit = -1;
        int second_last_fruit = -1;
        int last_fruit_count = 0;
        int curr_max = 0;
        int maxm = 0;

        for(int fruit: fruits) {
            if(fruit == last_fruit || fruit == second_last_fruit) {
                curr_max += 1;
            } else {
                curr_max = last_fruit_count + 1;
            }

            if(fruit == last_fruit) {
                last_fruit_count += 1;
            } else {
                last_fruit_count = 1;
            }

            if(fruit != last_fruit) {
                second_last_fruit = last_fruit;
                last_fruit = fruit;
            }

            maxm = max(maxm, curr_max);
        }

        return maxm;
    }
};