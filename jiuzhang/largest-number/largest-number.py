"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:	
    # @param num: A list of non negative integers
    # @return: A string
    def largestNumber(self, num):
        nums = sorted(num, cmp=lambda x, y: 1 if str(x) + str(y) < str(y) + str(x) else -1)
        largest = "".join([str(x) for x in nums])
        i, length = 0, len(largest)
        while i + 1 < length:
            if largest[i] != "0":
                break
            i += 1
        return largest[i:]

