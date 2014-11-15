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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode * next = head->next;
        head->next = NULL;
        while (next) {
            next = insertionSortHelper(head, next);
        }
        return head;
    }
private:
    ListNode * insertionSortHelper(ListNode * &head, ListNode * next) {
        ListNode * cur = head;
        ListNode * prev = NULL;
        ListNode * node;
        while (cur != NULL) {
            if (cur->val <= next->val ) {
                prev = cur;
                cur = cur->next;
            }
            else {
                node = next->next;
                next->next = cur;
                if (prev)
                    prev->next = next;
                else
                    head = next;
                break;
            }
        }
        
        if (cur == NULL) {
            if (prev)
                prev->next = next;
            node = next->next;
            next->next = NULL;
        }
        
        return node;
        
    }
};