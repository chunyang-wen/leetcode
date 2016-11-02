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
    # @param headA: the first list
    # @param headB: the second list
    # @return: a ListNode
    def getIntersectionNode(self, headA, headB):
        # Write your code here
        listA = []
        listB = []
        if headA == None or headB == None:
            return None
        while 1:
            if headA == None:
                break;
            listA.append(headA.val)
            headA = headA.next

        while 1:
            if headB == None:
                break;
            listB.append(headB.val)
            headB = headB.next

        if listA[-1] != listB[-1]:
            return None;
        
        if len(listA)<len(listB):
            minLen = len(listA)
        else:
            minLen = len(listB)

        inster = []
        for i in range(1,minLen+1):
            if listA[-i] != listB[-i]:
                return ListNode(listA[-i+1])
            if i == minLen:
                return ListNode(listA[-i])

