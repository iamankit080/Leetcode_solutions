class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        //create a max heap and store all array elements
     priority_queue<int> pq(stones.begin(),stones.end());
        
        //loop will run till size > 1
        while(pq.size() > 1)
        {
            //take first element 
            int f=pq.top();
            
            pq.pop();
            //take 2nd element 
            int s=pq.top();
            pq.pop();
            
            //if both are not equal 
            //and if both are equal numbers are destroyed from pq
            if(f!=s)
            {
                pq.push(f-s);
            }
        }
        return pq.empty()?0:pq.top(); 
    }
         
};