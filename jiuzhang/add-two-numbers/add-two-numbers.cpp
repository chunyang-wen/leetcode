/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 题意可以认为是实现高精度加法
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        int carry = 0;
        while (true) {
            if (l1 != NULL) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                carry += l2->val;
                l2 = l2->next;
            }
            ptr->val = carry % 10;
            carry /= 10;
            // 当两个表非空或者仍有进位时需要继续运算，否则退出循环
            if (l1 != NULL || l2 != NULL || carry != 0) {
                ptr = (ptr->next = new ListNode(0));
            } else break;
        }
        return head;
    }
};
