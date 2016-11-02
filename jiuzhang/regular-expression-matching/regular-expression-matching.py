"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    """
    @param s: A string 
    @param p: A string includes "." and "*"
    @return: A boolean
    """
    hash = None
    def isMatch(self, s, p):
        if self.hash is None:
            self.hash = {}
        key = s + p
        if key in self.hash:
            return self.hash[key]
            
        if p == "":
            return s == ""
        if s == "":
            if len(p) % 2 == 1:
                return False
            i = 1
            while i < len(p):
                if p[i] != "*":
                    return False
                i += 2
            return True
        
        if len(p) > 1 and p[1] == "*":
            if p[0] == ".":
                self.hash[key] = self.isMatch(s[1:], p) or self.isMatch(s, p[2:])
            elif p[0] == s[0]:
                self.hash[key] = self.isMatch(s[1:], p) or self.isMatch(s, p[2:])
            else:
                self.hash[key] = self.isMatch(s, p[2:])
        elif p[0] == ".":
            self.hash[key] = self.isMatch(s[1:], p[1:])
        else:
            self.hash[key] = s[0] == p[0] and self.isMatch(s[1:], p[1:])
        
        return self.hash[key]

class Solution(object):
    # DP
    def isMatch(self, s, p):
        dp = [[False for i in range(0,len(p) + 1)] for j in range(0, len(s) + 1)]
        dp[0][0] = True
        for i in range(1, len(p) + 1):
            if (p[i - 1] == "*"):
                dp[0][i] = dp[0][i - 2]
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j - 1] == "*":
                    dp[i][j] = dp[i][j - 2]
                    if s[i - 1] == p[j - 2] or p[j - 2] == ".":
                        dp[i][j] |= dp[i-1][j]
                else:
                    if s[i - 1] == p[j - 1] or p[j - 1] == ".":
                        dp[i][j] = dp[i - 1][j - 1]
    
        return dp[len(s)][len(p)]

    # 懒癌版
    def isMatch(self, s, p):
        return re.match(p + "$", s) != None
