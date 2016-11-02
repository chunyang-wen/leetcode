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
    # @param k, an integer
    # @return a ListNode
    def reverse(self, start, end):
        # Write your code here
        newhead=ListNode(0); newhead.next=start
        while newhead.next!=end:
            tmp=start.next
            start.next=tmp.next
            tmp.next=newhead.next
            newhead.next=tmp
        return [end, start]
    def reverseKGroup(self, head, k):
        if head==None: return None
        nhead=ListNode(0); nhead.next=head; start=nhead
        while start.next:
            end=start
            for i in range(k-1):
                end=end.next
                if end.next==None: return nhead.next
            res=self.reverse(start.next, end.next)
            start.next=res[0]
            start=res[1]
        return nhead.next
