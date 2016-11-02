/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector > &matrix, int target) {
        int n = matrix.size();
        if (n == 0) {
            return false;
        }
        
        int m = matrix[0].size();
        if (m == 0) {
            return false;
        }
        
        int start = 0, end = n * m - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int row = mid / m;
            int col = mid % m;
            
            if (matrix[row][col] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (matrix[start / m][start % m] == target) {
            return true;
        }
        
        if (matrix[end / m][end % m] == target) {
            return true;
        }
        
        return false;
    }
};

