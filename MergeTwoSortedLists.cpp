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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode * head;
        l1->val < l2->val ? (head = l1, l1=l1->next):(head = l2, l2 = l2->next);
        
        ListNode * cur = head;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        while (l1) {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }

        

        while (l2) {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }

        
        return head;
        
        
    }
};