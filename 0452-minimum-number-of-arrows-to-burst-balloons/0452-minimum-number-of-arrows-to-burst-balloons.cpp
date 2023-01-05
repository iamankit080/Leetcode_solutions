class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cntArrow=1, endDiameter=points[0][1];
        for(vector<int> &v:points){
            if(v[0]<=endDiameter) endDiameter=min(endDiameter,v[1]);
            else{
                cntArrow++;
                endDiameter=v[1];
            }
        }
        return cntArrow;
    }
};