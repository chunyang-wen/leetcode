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
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    # @param {TreeNode} root the root of the binary tree
    # @return {List[str]} all root-to-leaf paths
    def binaryTreePaths(self, root):
        # Write your code here
        result = []
        if root is None:
            return result
        self.dfs(root, result, [])
        return result

    def dfs(self, node, result, tmp):
        tmp.append(str(node.val))
        if node.left is None and node.right is None:
            result.append("->".join(tmp))
            tmp.pop()
            return

        if node.left:
            self.dfs(node.left, result, tmp);
        
        if node.right:
            self.dfs(node.right, result, tmp)

        tmp.pop()

