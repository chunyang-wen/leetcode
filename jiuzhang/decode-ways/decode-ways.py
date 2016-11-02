"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param {string} s a string,  encoded message
    # @return {int} an integer, the number of ways decoding
    def numDecodings(self, s):
        # Write your code here
        if s == "" or s[0] == "0":
            return 0

        dp=[1,1]
        for i in range(2,len(s) + 1):
            if 10 <= int(s[i - 2 : i]) <=26 and s[i - 1] != "0":
                dp.append(dp[i - 1] + dp[i - 2])
            elif int(s[i-2 : i]) == 10 or int(s[i - 2 : i]) == 20:
                dp.append(dp[i - 2])
            elif s[i-1] != "0":
                dp.append(dp[i-1])
            else:
                return 0

        return dp[len(s)]

