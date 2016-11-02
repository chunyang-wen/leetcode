"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    """
    @param source: A string
    @param target: A string
    @return: A string denote the minimum window
             Return "" if there is no such a string
    """
    def minWindow(self, source, target):
        if (target == ""):
            return ""
        S , T = source, target
        d, dt = {}, dict.fromkeys(T, 0)
        for c in T: d[c] = d.get(c, 0) + 1
        pi, pj, cont = 0, 0, 0
        if (source =="" or target ==""):
            return ""
        ans = ""
        while pj < len(S):
            if S[pj] in dt:
                if dt[S[pj]] < d[S[pj]]:
                    cont += 1
                dt[S[pj]] += 1;
            if cont == len(T):
                while pi < pj:
                    if S[pi] in dt:
                        if dt[S[pi]] == d[S[pi]]:
                            break;
                        dt[S[pi]] -= 1;
                    pi+= 1
                if ans == "" or pj - pi < len(ans):
                    ans = S[pi:pj+1]
                dt[S[pi]] -= 1
                pi += 1
                cont -= 1
            pj += 1
        return ans

