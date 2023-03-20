class Solution {
private:
    bool isPos(vector<int> &arr, int k, int idx){
        int n = arr.size();
        for(int i = idx; i < n; i += 2){
            if( arr[i] == 0 ){
                bool flag = true;
                if( i != 0 )
                    flag &= (arr[i - 1] != 1);
                if( i != n - 1 )
                    flag &= (arr[i + 1] != 1);
                k -= flag;
            }
            if( k <= 0 ) return 1;
        }
        return 0;
    }

public:
    bool canPlaceFlowers(vector<int>& fl, int n) {
        bool flag = isPos(fl, n, 0) || isPos(fl, n, 1);
        return flag;
    }
};