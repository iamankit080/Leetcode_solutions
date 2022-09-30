class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>>edges;
        int left, right, height;
        for (auto b: buildings){
            left = b[0] ; 
            right = b[1];
            height = b[2];
            edges.push_back({left, -height}); 
            edges.push_back({right, height});

}
        sort(edges.begin(), edges.end());
        vector<vector<int>>result; 
        multiset<int>m;
            m.insert(0);
        //pre> previous max height
        //curr-> current height
        int pre = 0 , curr = 0;
        for(int i = 0 ;i<edges.size(); i++){
            pair<int, int>e = edges[i];
            //if -ve, it's a starting point, insert in set m.insert(-e.second)
            if(e.second < 0){
                m.insert(-e.second);
            }else{ //erase from set, it's end point
                m.erase(m.find(e.second)); 
            }
            //find max
            curr=*m.rbegin();
                //max changed
            if(curr != pre){
                result.push_back({e.first, curr});
                pre = curr;
            }
        }

return result;
        
    }
};