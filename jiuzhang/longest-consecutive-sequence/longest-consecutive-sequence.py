"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        num.sort()
        l = num[0] 
        ans = 1
        tmp = 1
        for n in num:
            if(n - l == 0):
                continue;
            elif(n - l == 1):
                tmp += 1
            else:
                if tmp > ans:
                    ans = tmp
                tmp = 1
            l = n
        if tmp > ans:
            ans = tmp
        return ans

