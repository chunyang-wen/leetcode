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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode *leftDummy = new ListNode(0);
        ListNode *rightDummy = new ListNode(0);
        ListNode *leftTail = leftDummy;
        ListNode *rightTail = rightDummy;
        
        while (head != NULL) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = head;
            } else {
                rightTail->next = head;
                rightTail = head;
            }
            head = head->next;
        }
        
        leftTail->next = rightDummy->next;
        rightTail->next = NULL;
        
        return leftDummy->next;
    }
};



