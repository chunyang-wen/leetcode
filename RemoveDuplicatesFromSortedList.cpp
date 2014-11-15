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
        
        if (!head)
            return head;
        
        // use pointer to pointer, avoid prev pointer
        ListNode** start = &head;
        ListNode* node = NULL;
        while (*start) {
            if ((*start)->next) {
                if ((*start)->val == (*start)->next->val) {
                    node = (*start)->next;
                    (*start)->next = (*start)->next->next;
                    free(node);
                }
                else {
                    start = &((*start)->next);
                }
                continue;
            }
            break;
        }
        
        return head;
        
    }
};