"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        # write your code here
        n = len(gas)        
        diff = []
        for i in xrange(n): diff.append(gas[i]-cost[i])
        for i in xrange(n): diff.append(gas[i]-cost[i])
        if n==1:
            if diff[0]>=0: return 0
            else: return -1
        st = 0
        now = 1
        tot = diff[0]
        while st<n:
            while tot<0:
                st = now
                now += 1
                tot = diff[st]
                if st>n: return -1
            while now!=st+n and tot>=0:
                tot += diff[now]
                now += 1
            if now==st+n and tot>=0: return st
        return -1

