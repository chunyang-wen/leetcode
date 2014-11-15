class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int left,right;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!i && !j)
                    continue;
                if (i-1<0) {
                    left = INT_MAX;
                }
                else
                    left = grid[i-1][j];
                if (j-1<0) {
                    right = INT_MAX;
                }
                else
                    right = grid[i][j-1];
                
                grid[i][j] += (left<right?left:right);
                    
            }
        }
        
        return grid[m-1][n-1];
    }
};