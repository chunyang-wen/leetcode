class Solution {      
public:      
    vector<int> spiralOrder(vector<vector<int> >& matrix) {      
        vector<int> result;      
        if (matrix.empty()) return result;      
        ssize_t beginX = 0, endX = matrix[0].size() - 1;      
        ssize_t beginY = 0, endY = matrix.size() - 1;      
  
        while (true) {      
            // From left to right      
            for (ssize_t i = beginX; i <= endX; ++i)      
                result.push_back(matrix[beginY][i]);      
            if (++beginY > endY) break;      
  
            // From top down      
            for (ssize_t i = beginY; i <= endY; ++i)      
                result.push_back(matrix[i][endX]);      
            if (beginX > --endX) break;      
  
            // From right to left      
            for (ssize_t i = endX; i >= beginX; --i)      
                result.push_back(matrix[endY][i]);      
            if (beginY > --endY) break;      
  
            // From bottom up      
            for (ssize_t i = endY; i >= beginY; --i)      
                result.push_back(matrix[i][beginX]);      
            if (++beginX > endX) break;      
        }      
        return result;      
    }      
};      