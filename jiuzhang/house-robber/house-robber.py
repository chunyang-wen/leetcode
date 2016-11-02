"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param A: A list of non-negative integers.
    # return: an integer
    def houseRobber(self, A):
        # write your code here
        result = 0
        f, g, f1, g1 = 0, 0, 0, 0
        for x in A:
            f1 = g + x
            g1 = max(f, g)
            g, f = g1, f1
       
        return max(f, g)
