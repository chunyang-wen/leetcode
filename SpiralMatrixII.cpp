class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n));      
        ssize_t beginX = 0, endX = n - 1;      
        ssize_t beginY = 0, endY = n - 1;      
        int cur = 1;
  
        while (true) {      
            // From left to right      
            for (ssize_t i = beginX; i <= endX; ++i,++cur)      
                matrix[beginY][i] = cur;      
            if (++beginY > endY) break;      
  
            // From top down      
            for (ssize_t i = beginY; i <= endY; ++i,++cur)      
                matrix[i][endX] = cur;      
            if (beginX > --endX) break;      
  
            // From right to left      
            for (ssize_t i = endX; i >= beginX; --i,++cur)      
                matrix[endY][i] = cur;      
            if (beginY > --endY) break;      
  
            // From bottom up      
            for (ssize_t i = endY; i >= beginY; --i,++cur)      
                matrix[i][beginX] = cur;      
            if (++beginX > endX) break;      
        }    
        
        return matrix;
    }
};