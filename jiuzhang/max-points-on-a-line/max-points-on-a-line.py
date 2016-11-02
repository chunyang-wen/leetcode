"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    # @param {int[]} points an array of point
    # @return {int} an integer
    def maxPoints(self, points):
        # Write your code here
        len_points = len(points)
        if len_points <= 1:
            return len_points
        max_count = 0
        for index1 in range(0, len_points):
            p1 = points[index1]
            gradients = {}
            infinite_count = 0
            duplicate_count = 0
            for index2 in range(index1, len_points):
                p2 = points[index2]
                dx = p2.x - p1.x
                dy = p2.y - p1.y
                if 0 == dx and 0 == dy:
                    duplicate_count += 1
                if 0 == dx:
                    infinite_count += 1
                else:
                    g = float(dy) / dx
                    gradients[g] = (gradients[g] + 1 if gradients.has_key(g) else 1)
            if infinite_count > max_count:
                max_count = infinite_count
            for k, v in gradients.items():
                v += duplicate_count
                if v > max_count:
                    max_count = v
        return max_count

