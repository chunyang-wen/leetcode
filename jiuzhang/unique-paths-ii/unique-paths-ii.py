"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:

    def uniquePathsWithObstacles(self, obstacleGrid):
        mp = obstacleGrid
        for i in range(len(mp)):
            for j in range(len(mp[i])):
                if i == 0 and j == 0:
                    mp[i][j] = 1 - mp[i][j]
                elif i == 0:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i][j - 1]
                elif j == 0:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i - 1][j]
                else:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i - 1][j] + mp[i][j - 1]
        if mp[-1][-1] > 2147483647: 
            return -1
        else:
            return mp[-1][-1]


