"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution(object):
    """
        题意：求数列中三个数之和为0的三元组有多少个，需去重
        暴力枚举三个数复杂度为O(N^3)
        先考虑2Sum的做法，假设升序数列a，对于一组解ai,aj, 另一组解ak,al 
        必然满足 il 或 i>k j<l, 因此我们可以用两个指针，初始时指向数列两端
        指向数之和大于目标值时，右指针向左移使得总和减小，反之左指针向右移
        由此可以用O(N)的复杂度解决2Sum问题，3Sum则枚举第一个数O(N^2)
        使用有序数列的好处是，在枚举和移动指针时值相等的数可以跳过，省去去重部分
    """
    def threeSum(self, nums):
        nums.sort()
        res = []
        length = len(nums)
        for i in range(0, length - 2):
            if i and nums[i] == nums[i - 1]:
                continue
            target = nums[i] * -1
            left, right = i + 1, length - 1
            while left < right:
                if nums[left] + nums[right] == target:
                    res.append([nums[i], nums[left], nums[right]])
                    right -= 1
                    left += 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                elif nums[left] + nums[right] > target:
                    right -= 1
                else:
                    left += 1
        return res
