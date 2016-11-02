/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: the node where the cycle begins. 
     *           If there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        ListNode* ptr1,* ptr2;
        if(head == NULL)
            return NULL;
        ptr1 = head ;
        ptr2 = head;

        while(ptr2->next != NULL && ptr2->next->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1 == ptr2)
            {
                ptr1 = head;
                while(ptr1 != ptr2)
                {
                    ptr2 = ptr2->next;
                    ptr1 = ptr1->next;
                }
                return ptr1;
            }

        }
        return NULL;
    }
};




