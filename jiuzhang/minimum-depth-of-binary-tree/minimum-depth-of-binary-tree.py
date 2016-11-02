"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""
class Solution:
    """
    @param root: The root of binary tree.
    @return: An integer
    """ 
    def minDepth(self, root):
        # write your code here
        return self.find(root)

    def find(self, node):
        if node is None:
            return 0
        left, right = 0, 0
        if node.left != None:
            left = self.find(node.left)
        else:
            return self.find(node.right) + 1

        if node.right != None:
            right = self.find(node.right)
        else:
            return left + 1

        return min(left,right) + 1

