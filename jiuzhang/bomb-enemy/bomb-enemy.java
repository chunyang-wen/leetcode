/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    /**
     * @param grid Given a 2D grid, each cell is either "W", "E" or "0"
     * @return an integer, the maximum enemies you can kill using one bomb
     */
    public int maxKilledEnemies(char[][] grid) {
        // Write your code here
        int m = grid.length;
        int n = m > 0 ? grid[0].length : 0;

        int result = 0, rows = 0;
        int[] cols = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0 || grid[i][j-1] == "W") {
                    rows = 0;
                    for (int k = j; k < n && grid[i][k] != "W"; ++k)
                        if (grid[i][k] == "E")
                            rows += 1;
                }
                if (i == 0 || grid[i-1][j] == "W") {
                    cols[j] = 0;
                    for (int k = i; k < m && grid[k][j] != "W"; ++k)
                        if (grid[k][j] == "E")
                            cols[j] += 1;
                }

                if (grid[i][j] == "0" && rows + cols[j] > result)
                    result = rows + cols[j];
            }
        }
        return result;
    }
}

