"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:  
    # @param head, a ListNode  
    # @return a ListNode  
    def deleteDuplicates(self, head):  
        if None == head or None == head.next:  
            return head  
  
        new_head = ListNode(-1)  
        new_head.next = head  
        parent = new_head  
        cur = head  
        while None != cur and None != cur.next:   ### check cur.next None  
            if cur.val == cur.next.val:  
                val = cur.val  
                while None != cur and val == cur.val: ### check cur None  
                    cur = cur.next  
                parent.next = cur  
            else:  
                cur = cur.next  
                parent = parent.next  
  
        return new_head.next 

