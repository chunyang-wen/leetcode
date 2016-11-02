/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head ->next == NULL) {
            return true;
        }
        ListNode* mid = findmid(head);
        mid->next = reverse(mid->next);
        mid = mid->next;
        while(head!=NULL && mid!=NULL) {
            if(head->val != mid->val) {
                return false;
            }
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
    ListNode * findmid(ListNode * now) {
        ListNode* slow = now;
        ListNode* fast = now ->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode * reverse(ListNode *now) {
        ListNode * pre = NULL;
        while(now!=NULL) {
            ListNode *temp = now->next;
            now->next = pre;
            pre = now;
            now = temp;
        }
        return pre;
    }
};
