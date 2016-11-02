"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    """
	@param A : An integer array
	@return : An integer
    """
    def singleNumberII(self, A):
        # write your code here
        n = len(A)
        d = [0 for i in xrange(32)]
        for x in A:
            for j in xrange(32):
                if ( ((1  0):
                    d[j] += 1
        ans = 0
        for j in xrange(32):
            t = d[j] % 3
            if (t == 1):
                ans  = ans + (1 << j)
            elif (t != 0):
                return -1
        return ans
        

