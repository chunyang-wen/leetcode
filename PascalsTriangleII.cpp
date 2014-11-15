class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> res(rowIndex+1,1);
        
        if (rowIndex < 2) {
            return res;
        }
        
        int prev,next;
        for (int i = 2; i < rowIndex+1; ++i) {
            
            prev = 1;
            for (int j = 1; j < i; ++j) {
                next = res[j];
                res[j] = prev + res[j];
                prev = next;
            }
            
        }
        
        return res;
        
    }
};