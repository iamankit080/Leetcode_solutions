class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int mis= 0;                         //count
        int it = 0;                         //iterator for for loop
        for(int i=1 ; i<=arr.back();i++){   //here, i== current integer
            if(arr[it]==i){
                it++;
            }else
            {
                mis++;
            }
            if(mis==k)
            {
                return i;
            }
        }

        return arr.back()+k-mis;
    }
};