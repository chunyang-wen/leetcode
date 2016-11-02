"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean
    def exist(self, board, word):
        # write your code here
        # Boundary Condition
        if word == []:
            return True
        m = len(board)
        if m == 0:
            return False
        n = len(board[0])
        if n == 0:
            return False
        # Visited Matrix
        visited = [[False for j in range(n)] for i in range(m)]
        # DFS
        for i in range(m):
            for j in range(n):
                if self.exist2(board, word, visited, i, j):
                    return True
        return False

    def exist2(self, board, word, visited, row, col):
        m, n = len(board), len(board[0])
        if row = m or col < 0 or col >= n:
            return False
        if word == "":
            return True
        if board[row][col] == word[0] and not visited[row][col]:
            visited[row][col] = True
            # row - 1, col
            if self.exist2(board, word[1:], visited, row - 1, col) or self.exist2(board, word[1:], visited, row, col - 1) or self.exist2(board, word[1:], visited, row + 1, col) or self.exist2(board, word[1:], visited, row, col + 1):
                return True
            else:
                visited[row][col] = False
        return False
