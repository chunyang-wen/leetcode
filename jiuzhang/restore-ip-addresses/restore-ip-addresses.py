"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param s, a string
    # @return a list of strings
    def restoreIpAddresses(self, s):
        def dfs(s, sub, ips, ip):
            if sub == 4:                                        # should be 4 parts
                if s == "":
                    ips.append(ip[1:])                          # remove first "."
                return
            for i in range(1, 4):                               # the three ifs" order cannot be changed!
                if i  len(s), s[:i] will make false!!!!
                    if int(s[:i]) <= 255:
                        dfs(s[i:], sub+1, ips, ip+"."+s[:i])
                    if s[0] == "0": break                       # make sure that res just can be "0.0.0.0" and remove like "00"
        ips = []
        dfs(s, 0, ips, "")
        return ips

