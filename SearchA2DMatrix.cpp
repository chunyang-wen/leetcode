class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = n-1;
        int j = 0;
        while (true) {
            
            if (matrix[j][i] > target) {
                if (i>0)
                    --i;
                else
                    break;
            }
            else if (matrix[j][i] < target) {
                if (j < m-1)
                    ++j;
                else
                    break;
            }
            else
                return true;
            
        }
        return false;
    }
};