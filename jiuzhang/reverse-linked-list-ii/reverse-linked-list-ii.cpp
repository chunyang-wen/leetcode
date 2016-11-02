/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include "lintcode.h"

using namespace std;


class Solution {
public:
    void reverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
    }

    ListNode *findkth(ListNode *head, int k) {
        for (int i = 0; i < k; i++) {
            if (head == NULL) {
                return NULL;
            }
            head = head->next;
        }
        return head;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *mth_prev = findkth(dummy, m - 1);
        ListNode *mth = mth_prev->next;
        ListNode *nth = findkth(dummy, n);
        ListNode *nth_next = nth->next;
        nth->next = NULL;

        reverse(mth);
        mth_prev->next = nth;
        mth->next = nth_next;
        return dummy->next;
    }
};

