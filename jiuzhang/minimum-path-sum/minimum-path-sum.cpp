/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector > &grid) {
        // write your code here
        int f[1000][1000];
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        f[0][0] = grid[0][0];
        for(int i = 1; i < grid.size(); i++)
            f[i][0] = f[i-1][0] + grid[i][0];
        for(int i = 1; i < grid[0].size(); i++)
            f[0][i] = f[0][i-1] + grid[0][i];
        for(int i = 1; i < grid.size(); i++)
            for(int j = 1; j < grid[0].size(); j++)
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
                
        return f[grid.size()-1][grid[0].size()-1];
    }
};


