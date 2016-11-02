"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution: 
    # @param S, T: Two string.
    # @return: Count the number of distinct subsequences
    def numDistinct(self, S, T):
        # write your code here
        dp = [[0 for j in range(len(T) + 1)] for i in range(len(S) + 1)]
        for i in range(len(S) + 1):
   			dp[i][0] = 1
        for i in xrange(len(S)):
            for j in xrange(len(T)):
                if S[i] == T[j]:
                    dp[i+1][j+1] = dp[i][j+1] + dp[i][j]
                else:
                    dp[i+1][j+1] = dp[i][j + 1]
        return dp[len(S)][len(T)]
                

