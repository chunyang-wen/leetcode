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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *root = NULL;
        ListNode **ppNext = &root;
        while(head) {
            if(head->next == NULL || head->next->val != head->val) {
                *ppNext = head;
                ppNext = &(head->next);
                head = head->next;
            } else {
                int val = head->val;
                do {
                    head = head->next;
                } while(head != NULL && head->val == val);
            }
        }
        *ppNext = NULL;
        return root;
    }
};
