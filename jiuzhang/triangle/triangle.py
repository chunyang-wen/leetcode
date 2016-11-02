"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    """
    @param triangle: a list of lists of integers.
    @return: An integer, minimum path sum.
    """
    def minimumTotal(self, triangle):
        # write your code here
        res=[triangle[0]]
        N = len(triangle)
        for i in range(1,len(triangle)):
            res.append([])
            for j in range(len(triangle[i])):
                if j-1>=0 and j< len(triangle[i-1]):
                    res[i].append(min(res[i-1][j-1],res[i-1][j])+triangle[i][j])
                elif j-1>=0:
                    res[i].append(res[i-1][j-1]+triangle[i][j])
                else:
                    res[i].append(res[i-1][j]+triangle[i][j])
                 
        minvalue = min(res[N-1])
        return minvalue

