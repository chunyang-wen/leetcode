class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rows(m,false);
        vector<bool> columns(n,false);
        int i,j;
        for(i = 0; i < m ; ++i) {
            for (j = 0;j < n; ++j) {
                if(matrix[i][j] == 0) {
                    rows[i] = true;
                    columns[j] = true;
                }
            }
        }
        
        for (i = 0; i < m ; ++i) {
            if(rows[i]) {
                memset(&matrix[i][0],0, sizeof(int)*n);
            }
            else {
                for(j = 0; j < n; ++j) {
                    if(columns[j])
                        matrix[i][j] = 0;
                }
            }
        }
    }
};