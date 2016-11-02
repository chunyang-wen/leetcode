"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    """
    @param A : An integer array
    @return : Two integer
    """
    def singleNumberIII(self, A):
        # write your code here
        s = 0
        for x in A:
            s ^= x
        y = s & (-s)

        ans = [0,0]
        for x in A:
            if (x & y) != 0:
                ans[0] ^= x
            else:
                ans[1] ^= x                 
        return ans
        
        

