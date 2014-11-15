class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int i = 0;
        int len = gas.size();
        int j = len - 1;
        
        int start = i;
        
        int remainGas = 0;
        
        while (j >= i) {
            
            remainGas += (gas[i] - cost[i]);
            while (remainGas <0) {
                if (j < i)
                    return -1;
                remainGas += (gas[j]-cost[j]);
                start = j;
                --j;
            }
            
            i++;
            
        }
        
        return start;
    }
};