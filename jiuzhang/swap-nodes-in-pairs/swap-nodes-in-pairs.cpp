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
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if(head==NULL || head->next==NULL) return head;
        ListNode *helper=new ListNode(0);
        ListNode *ret=head;
        ListNode *cur=helper;
        while(ret  && ret->next) {
            ListNode *next=ret->next->next;
            cur->next=ret->next;
            cur=cur->next;
            cur->next=ret;
            cur=cur->next;
            cur->next=NULL;
            ret=next;
        }
        if(ret) cur->next=ret;
        return helper->next;
    }
};

