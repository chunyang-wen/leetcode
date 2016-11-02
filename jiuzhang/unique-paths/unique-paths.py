"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @return an integer
    def c(self, m, n):
        mp = {}
        for i in range(m):
            for j in range(n):
                if(i == 0 or j == 0):
                    mp[(i, j)] = 1
                else:
                    mp[(i, j)] = mp[(i - 1, j)] + mp[(i, j - 1)]
        return mp[(m - 1, n - 1)]

    def uniquePaths(self, m, n):
        return self.c(m, n)
