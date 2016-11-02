"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    def _connect(self, prev, curt):
        if prev is not None:
            prev.next = curt
        
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root is None:
            return
        
        parent = root
        root.next = None
        while parent is not None:
            last, first = None, None
            while parent is not None:
                for node in [parent.left, parent.right]:
                    if node is None:
                        continue
                    self._connect(last, node)
                    if last is None:
                        first = node
                    last = node
                parent = parent.next
            parent = first
