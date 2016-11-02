"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param {int} n the integer to be reversed
    # @return {int} the reversed integer
    def reverseInteger(self, n):
        if n == 0:
            return 0
            
        neg = 1
        if n < 0:
            neg, n = -1, -n
        
        reverse = 0
        while n > 0:
            reverse = reverse * 10 + n % 10
            n = n / 10
        
        reverse = reverse * neg
        if reverse  (1 << 31) - 1:
            return 0
        return reverse
