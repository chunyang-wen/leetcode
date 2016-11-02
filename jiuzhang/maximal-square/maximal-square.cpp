/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector > &matrix) {
        // write your code here
        int m = matrix.size(), n = matrix[0].size();
        vector > f(m, vector<int>(n));
        for (int i=0; i<n; ++i) f[0][i] = matrix[0][i];
        for (int i=1; i<m; ++i) f[i][0] = matrix[i][0];
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j) 
                if (matrix[i][j]==0) f[i][j] = 0;
                else f[i][j] = 1+min(f[i-1][j], min(f[i-1][j-1], f[i][j-1]));
        int ans = 0;        
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) ans = max(ans, f[i][j]);
        return ans*ans;
    }
};

