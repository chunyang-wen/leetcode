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
    # @param head, a ListNode
    # @return a boolean
    def isPalindrome(self, head):
        # Write your code here
        if head is None:
            return True

        fast = slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        p, last = slow.next, None
        while p:
            next = p.next
            p.next = last
            last, p = p, next

        p1, p2 = last, head
        while p1 and p1.val == p2.val:
            p1, p2 = p1.next, p2.next

        p, last = last, None
        while p:
            next = p.next
            p.next = last
            last, p = p, next
            slow.next = last
        return p1 is None

