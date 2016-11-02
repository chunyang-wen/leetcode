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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* iter1 = headA;
        ListNode* iter2 = headB;
        int len1 = 1;
        while(iter1->next != NULL)
        {
            iter1 = iter1->next;
            len1 ++;
        }
        int len2 = 1;
        while(iter2->next != NULL)
        {
            iter2 = iter2->next;
            len2 ++;
        }
        if(iter1 != iter2)
            return NULL;
        if(len1 > len2)
        {
            for(int i = 0; i < len1-len2; i ++)
                headA = headA->next;
        }
        else if(len2 > len1)
        {
            for(int i = 0; i < len2-len1; i ++)
                headB = headB->next;
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

