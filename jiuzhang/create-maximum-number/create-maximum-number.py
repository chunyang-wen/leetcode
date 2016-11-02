"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param {int[]} nums1 an integer array of length m with digits 0-9
    # @param {int[]} nums2 an integer array of length n with digits 0-9
    # @param {int} k an integer and k <= m + n
    # @return {int[]} an integer array
    def maxNumber(self, nums1, nums2, k):
        # Write your code here
        len1, len2 = len(nums1), len(nums2)
        res = []
        for x in range(max(0, k - len2), min(k, len1) + 1):
            tmp = self.merge(self.getMax(nums1, x), self.getMax(nums2, k - x))
            res = max(tmp, res)
        return res

    def getMax(self, nums, t):
        ans = []
        size = len(nums)
        for x in range(size):
            while ans and len(ans) + size - x > t and ans[-1] < nums[x]:
                ans.pop()
            if len(ans) < t:
                ans.append(nums[x])
        return ans

    def merge(self, nums1, nums2):
        return [max(nums1, nums2).pop(0) for _ in nums1 + nums2]

