"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param {int[]} digits a number represented as an array of digits
    # @return {int[]} the result
    def plusOne(self, digits):
        digits = list(reversed(digits))
        digits[0] += 1
        i, carry = 0, 0
        while i < len(digits):
            next_carry = (digits[i] + carry) / 10
            digits[i] = (digits[i] + carry) % 10
            i, carry = i + 1, next_carry
        if carry > 0:
            digits.append(carry)
        
        return list(reversed(digits))
