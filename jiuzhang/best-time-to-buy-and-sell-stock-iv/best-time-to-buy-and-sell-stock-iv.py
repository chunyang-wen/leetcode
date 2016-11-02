"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    """
    @param k: an integer
    @param prices: an integer array
    @return: an integer which is maximum profit
    """
    def maxProfit(self, k, prices):
        # write your code here
        size = len(prices)
        if k >= size / 2:
            return self.quickSolve(size, prices)
        dp = [None] * (2 * k + 1)
        dp[0] = 0
        for i in range(size):
            for j in range(min(2 * k, i + 1) , 0 , -1):
                dp[j] = max(dp[j], dp[j - 1] + prices[i] * [1, -1][j % 2])
        return max(dp)

    def quickSolve(self, size, prices):
        sum = 0
        for x in range(size - 1):
            if prices[x + 1] > prices[x]:
                sum += prices[x + 1] - prices[x]
        return sum
