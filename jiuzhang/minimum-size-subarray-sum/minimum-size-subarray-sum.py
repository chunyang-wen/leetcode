"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
     # @param nums: a list of integers
     # @param s: an integer
     # @return: an integer representing the minimum size of subarray
    def minimumSize(self, nums, s):
        # write your code here
        n = len(nums)
        if n==0: return -1
        left = right = total = 0 
        ans = n+1
        while right<n:
            while right<n and total<s: 
                total += nums[right]
                right += 1
            if total<s: break
            while left=s:
                total -= nums[left]
                left += 1
            ans = min(ans, right-left+1)
        if ans==n+1: return -1
        else: return ans 

