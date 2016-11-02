/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /*
    题意：删除链表中倒数第n个结点，尽量只扫描一遍。
    使用两个指针扫描，当第一个指针扫描到第N个结点后，
    第二个指针从表头与第一个指针同时向后移动，
    当第一个指针指向空节点时，另一个指针就指向倒数第n个结点了
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *tmp = res;
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
        while (head != NULL) {
            head = head->next;
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return res->next;
    }
};
