/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector > &matrix) {
        // write your code here
        if (matrix.size()==0)
            return ;
        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0) && matrix[i][j] == 0) {
                    row0 |= i == 0;
                    col0 |= j == 0;
                }
                else {
                    matrix[i][0] = matrix[i][j] == 0 ? 0 : matrix[i][0];
                    matrix[0][j] = matrix[i][j] == 0 ? 0 : matrix[0][j];                                        
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = matrix[i][0] == 0 || matrix[0][j] == 0 ? 0 : matrix[i][j];
            }
        }
        
        for (int i = 0; i < m && col0; i++) {
            matrix[i][0] = 0;
        }
        for (int j = 0; j < n && row0; j++) {
            matrix[0][j] = 0;
        }
    }
};

