"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution(object):
    """
    题意:任取两个a[i]、a[j] 使得min(a[i], a[j]) * abs(i - j)最大化
    用两个指针从两侧向中间扫描，每次移动数值较小的指针，用反证法可以证明
    总是可以得到最优答案
    """
    def maxArea(self, height):
        left, right = 0, len(height) - 1
        ans = 0
        while left != right:
            if height[left] < height[right]:
                area = height[left] * (right - left)
                left += 1
            else:
                area = height[right] * (right - left)
                right -= 1
            ans = max(ans, area) 
        return ans
