"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param {boolean[][]} grid a boolean 2D matrix
    # @return {int} an integer
    def numIslands(self, grid):
        # Write your code here
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        visit = [[False for i in range(n)]for j in range(m)]
        def check(x, y):
            if x >= 0 and x= 0 and y< n and grid[x][y] and visit[x][y] == False:
                return True
        def dfs(x,y):
            nbrow = [1,0,-1,0]
            nbcol = [0,1,0,-1]
            for k in range(4):
                newx = x + nbrow[k]
                newy = y + nbcol[k]
                if check(newx, newy):
                    visit[newx][newy] = True
                    dfs(newx,newy)
        count = 0
        for row in range(m):
            for col in range(n):
                if check(row,col):
                    visit[row][col] = True
                    dfs(row,col)
                    count+=1
        return count

