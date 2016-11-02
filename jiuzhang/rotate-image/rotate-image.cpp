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
    void rotate(vector > &matrix, size_t topleft, size_t bottomright)
    {
        for (size_t i = 0; i < bottomright - topleft; ++i)
        {
            int tmp = matrix[topleft][topleft + i];
            matrix[topleft][topleft + i] = matrix[bottomright - i][topleft];
            matrix[bottomright - i][topleft] = matrix[bottomright][bottomright - i];
            matrix[bottomright][bottomright - i] = matrix[topleft + i][bottomright];
            matrix[topleft + i][bottomright] = tmp;
        }
    }
    void rotate(vector > &matrix) {
        // write your code here
        if (matrix.size() <= 0)
            return ;
        size_t topleft = 0, bottomright = matrix.size() - 1;
        while (topleft < bottomright)
        {
            rotate(matrix, topleft, bottomright);
            ++topleft; --bottomright;
        }
    }
};

