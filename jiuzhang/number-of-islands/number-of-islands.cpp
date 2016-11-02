/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    void dfs(vector> &grid, int x, int y) {
        if (x = grid.size()) return;
        if (y = grid[0].size()) return;
        if (!grid[x][y]) return;
        grid[x][y] = false;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    int numIslands(vector>& grid) {
        // Write your code here
        if (grid.empty() || grid[0].empty()) return 0;
        int N = grid.size(), M = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

