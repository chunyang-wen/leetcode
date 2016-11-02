"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param nums: an integer[]
    # @return: an integer
    def maxProduct(self, nums):
        # write your code here
        f, g = [], []
        f.append(nums[0])
        g.append(nums[0])
        for i in xrange(1, len(nums)):
            f.append(max(f[i-1]*nums[i], g[i-1]*nums[i], nums[i]))
            g.append(min(f[i-1]*nums[i], g[i-1]*nums[i], nums[i]))
        m = f[0]
        for i in xrange(1, len(f)): m = max(m, f[i])
        return m

