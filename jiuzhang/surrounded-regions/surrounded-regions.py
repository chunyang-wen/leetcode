"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param {list[list[str]]} board a 2D board containing "X" and "O"
    # @return nothing 
    def surroundedRegions(self, board):
        def fill(x, y):
            if x  m-1 or y < 0 or y > n-1 or board[x][y] != "O":
                return
            queue.append((x,y))
            board[x][y] = "D"

        def bfs(x, y):
            if board[x][y]=="O":
                queue.append((x,y))
                fill(x,y)

            while queue:
                curr = queue.pop(0)
                i, j = curr[0], curr[1]
                fill(i+1, j)
                fill(i-1, j)
                fill(i, j+1)
                fill(i, j-1)

        if len(board) == 0:
            return
        m, n , queue = len(board), len(board[0]), []
        for i in range(n):
            bfs(0, i)
            bfs(m-1, i)

        for j in range(1, m-1):
            bfs(j, 0)
            bfs(j, n-1)

        for i in range(m):
            for j in range(n):
                if board[i][j] == "D":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"

