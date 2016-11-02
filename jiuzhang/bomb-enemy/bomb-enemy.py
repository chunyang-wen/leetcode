"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param {character[][]} grid Given a 2D grid, each cell is either "W", "E" or "0"
    # @return {int} an integer, the maximum enemies you can kill using one bomb
    def maxKilledEnemies(self, grid):
        # Write your code here
        m, n = len(grid), 0
        if m:
            n = len(grid[0])
        result, rows = 0, 0
        cols = [0 for i in xrange(n)]

        for i in xrange(m):
            for j in xrange(n):
                if j == 0 or grid[i][j-1] == "W":
                    rows = 0
                    for k in xrange(j, n):
                        if grid[i][k] == "W":
                            break
                        if grid[i][k] == "E":
                            rows += 1

                if i == 0 or grid[i-1][j] == "W":
                    cols[j] = 0
                    for k in xrange(i, m):
                        if grid[k][j] == "W":
                            break
                        if grid[k][j] == "E":
                            cols[j] += 1

                if grid[i][j] == "0" and rows + cols[j] > result:
                    result = rows + cols[j]

        return result

