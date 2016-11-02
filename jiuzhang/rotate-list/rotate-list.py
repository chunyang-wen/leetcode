"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head: the list
    # @param k: rotate to the right k places
    # @return: the list after rotation
    def rotateRight(self, head, k):
        # write your code here
        if head==None:
            return head
        curNode = head
        size = 1
        while curNode!=None:
            size += 1
            curNode = curNode.next
        size -= 1
        k = k%size
        if k==0:
            return head
        len = 1
        curNode = head
        while len<size-k:
            len += 1
            curNode = curNode.next
        newHead = curNode.next
        curNode.next = None
        curNode = newHead
        while curNode.next!=None:
            curNode = curNode.next
        curNode.next = head
        return newHead

