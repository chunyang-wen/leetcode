"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    """
    @param s: A string
    @param p: A string includes "?" and "*"
    @return: A boolean
    """
    def isMatch(self, s, p):
        # write your code here
        n = len(s)
        m = len(p)
        f = [[False] * (m + 1) for i in range(n + 1)]
        f[0][0] = True

        if n == 0 and p.count("*") == m:
            return True

        for i in range(0, n + 1):
            for j in range(0, m + 1):
                if i > 0 and j > 0:
                    f[i][j] |= f[i-1][j-1] and (s[i-1] == p[j-1] or p[j - 1] in ["?", "*"])

                if i > 0 and j > 0:
                    f[i][j] |= f[i - 1][j] and p[j - 1] == "*"

                if j > 0:
                    f[i][j] |= f[i][j - 1] and p[j - 1] == "*"


        return f[n][m]
