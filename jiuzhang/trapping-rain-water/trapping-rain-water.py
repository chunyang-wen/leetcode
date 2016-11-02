"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param heights: a list of integers
    # @return: an integer
    def trapRainWater(self, heights):
        # write your code here
        n = len(heights)
        if n==0: return 0
        pos = []
        neg = []

        p = q = 0
        pos.append(p)
        while (q<n-1):
            q += 1
            if (heights[p]<=heights[q]):
                pos.append(q)
                p = q
        
        p = q = n-1;
        neg.append(p)
        while (q>0):
            q -= 1
            if (heights[q]>heights[p]):
                neg.append(q)
                p = q
        
        ans = 0
        for i in xrange(len(pos)-1):
            for j in xrange(pos[i]+1, pos[i+1]):
                ans += heights[pos[i]]-heights[j]
        for i in xrange(len(neg)-1):
            for j in xrange(neg[i+1]+1, neg[i]):
                ans += heights[neg[i]]-heights[j]
        return ans
        

