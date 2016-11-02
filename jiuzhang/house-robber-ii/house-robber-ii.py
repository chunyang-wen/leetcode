"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param nums: A list of non-negative integers.
    # return: an integer
    def houseRobber2(self, nums):
        # write your code here
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]

        dp = [0] * n
        
        dp[0], dp[1] = 0, nums[1]
        for i in xrange(2, n):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

        answer = dp[n - 1]

        dp[0], dp[1] = nums[0], max(nums[0], nums[1])
        for i in xrange(2, n):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

        return max(dp[n - 2], answer)

