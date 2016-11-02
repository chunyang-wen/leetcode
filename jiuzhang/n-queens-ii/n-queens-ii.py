"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    """
    Calculate the total number of distinct N-Queen solutions
    @param n: The number of queens.
    @return: The total number of distinct solutions.
    """
    total = 0
    n = 0

    def attack(self, row, col):
        for c, r in self.cols.iteritems():
            if c - r == col - row or c + r == col + row:
                return True
        return False

    def search(self, row):
        if row == self.n:
            self.total += 1
            return
        for col in range(self.n):
            if col in self.cols:
                continue
            if self.attack(row, col):
                continue
            self.cols[col] = row
            self.search(row + 1)
            del self.cols[col]

    def totalNQueens(self, n):
        self.n = n
        self.cols = {}
        self.search(0)
        return self.total
