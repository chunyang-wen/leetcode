"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        ans = 0
        # left用于记录合法的左边界位置，last用于记录字符上一次出现的位置
        left = 0
        last = {}
        for i in range(len(s)):
            # 子串中出现重复字符，变更left至上一次s[i]出现位置之后，使得子串合法
            if s[i] in last and last[s[i]] >= left:
                left = last[s[i]] + 1
            last[s[i]] = i
            ans = max(ans, i - left + 1)
        return ans
