class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),curGas=0,gasVal=0,costVal=0,si=0;
        for(int i=0;i<n;i++){
            gasVal+=gas[i];
            costVal+=cost[i];
            curGas+=gas[i]-cost[i];
            if(curGas<0){
                si=i+1;
                curGas=0;
            }
        }
        return gasVal>=costVal?si:-1;
    }
};