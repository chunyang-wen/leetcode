"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param num: a rotated sorted array
    # @return: the minimum number in the array
    def findMin(self, num):
        # write your code here
        min = num[0]
        start, end = 0, len(num) - 1
        while start<end:
            mid = (start+end)/2
            if num[mid]>num[end]:
                start = mid+1
            elif num[mid]<num[end]:
                end = mid
            else:
                end = end - 1
        return num[start]

