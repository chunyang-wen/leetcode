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
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector > &matrix, int target) {
        // write your code here
        if (matrix.empty())
        {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m - 1;
        int j = 0;
        int occur = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] == target)
            {
                ++occur;
            }
            if (matrix[i][j] < target)
            {
                ++j;
            }
            else
            {
                --i;
            }
        }
        return occur;
    }
};


