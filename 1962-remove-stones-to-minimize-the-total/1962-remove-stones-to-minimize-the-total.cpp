class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      int sum = accumulate(piles.begin(), piles.end(), 0);
      priority_queue<int> pq(piles.begin(), piles.end());

      while(!pq.empty() && k--){
          int curr= pq.top();
          pq.pop();

          sum-= floor(curr/2);
          curr-=floor(curr/2);

          pq.push(curr);
      }  
      return sum;
    }
};