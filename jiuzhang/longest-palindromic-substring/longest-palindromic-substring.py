"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution(object):
    # Python O(N^2)常数比较大的话会TLE
    def longestPalindrome(self, s):
        ansl, ansr, maxx = 0, 1, 0
        length = len(s)
        for i in range(1, length * 2):
            if i & 1 :
                left = i / 2
                right = left
            else :
                left = i / 2 - 1
                right = left + 1
            while (left >= 0) and (right < length) and (s[left] == s[right]):
                left -= 1
                right += 1
            left += 1
            right -= 1
            if right - left > maxx:
                maxx = right - left
                ansl = left
                ansr = right
        return s[ansl: ansr + 1]
