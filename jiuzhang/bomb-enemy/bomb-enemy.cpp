/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param grid Given a 2D grid, each cell is either "W", "E" or "0"
     * @return an integer, the maximum enemies you can kill using one bomb
     */
     
    int maxKilledEnemies(vector>& grid) {
        // Write your code here
        int n = grid.size();
        int m = n > 0 ? grid[0].size() : 0;
        
        int left[n+2][m+2], right[n+2][m+2], up[n+2][m+2], down[n+2][m+2];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        
        // left
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i-1][j-1] == "E") {
                    left[i][j] = left[i][j-1] + 1;
                } else if (grid[i-1][j-1] == "W") {
                    left[i][j] = 0;
                } else {
                    left[i][j] = left[i][j-1];
                }
            }
        }
        
        // up
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                if (grid[i-1][j-1] == "E") {
                    up[i][j] = up[i-1][j] + 1;
                } else if (grid[i-1][j-1] == "W") {
                    up[i][j] = 0;
                } else {
                    up[i][j] = up[i-1][j];
                }
            }
        }
        
        // right
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (grid[i-1][j-1] == "E") {
                    right[i][j] = right[i][j+1] + 1;
                } else if (grid[i-1][j-1] == "W") {
                    right[i][j] = 0;
                } else {
                    right[i][j] = right[i][j+1];
                }
            }
        }
        
        // down
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                if (grid[i-1][j-1] == "E") {
                    down[i][j] = down[i+1][j] + 1;
                } else if (grid[i-1][j-1] == "W") {
                    down[i][j] = 0;
                } else {
                    down[i][j] = down[i+1][j];
                }
            }
        }
        
        int result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(grid[i-1][j-1] == "0") {
                    result = max(result, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
                }
            }
        }
        return result;
    }
};
