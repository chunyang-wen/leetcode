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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return head;
        ListNode ** start = &head;
        ListNode * end = head;
        while (n--) end = end->next;

        
        while (end) {
            start = &((*start)->next);
            end = end->next;
        }
        end = *start;
        *start = end->next;
        free(end);
        return head;
    }
};