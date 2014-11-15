class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {

        int len = triangle.size()-1;
        int subLen;
        int index;
        for (int i = len-1; i >= 0; --i) {
            subLen = triangle[i].size();
            index = 1;
            for (int j = 0; j < subLen; ++j) {
                triangle[i][j] += min(triangle[i+1][index-1], triangle[i+1][index]);
                ++index;
            }
        }
        return triangle[0][0];
    }
};