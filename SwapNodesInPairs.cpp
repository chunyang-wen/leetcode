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
    ListNode *swapPairs(ListNode *head) {
        // if (!head || !head->next)
        //     return head;
            
        // return swap(head, head->next);
        return swapPairsNonRercursive(head);
        
    }
private:
    ListNode *swap(ListNode *left, ListNode * right) {
        if (!left || !right)
            return left;
        ListNode * next = right->next;
        if (next) {
            left->next = swap(next, next->next);
        }
        else
            left->next = NULL;
        right->next = left;
        return right;
    }
    ListNode * swapPairsNonRercursive(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode * prev = head->next;
        ListNode * pairLeft, *pairRight;
        head->next = prev->next;
        prev->next = head;
        head = prev;
        
        prev = head->next;
        pairLeft = prev->next;
        
        while (pairLeft) {
            
            pairRight = pairLeft->next;
            if (pairRight) {
                // swap prev and its next;
                prev->next = pairRight;
                pairLeft->next = pairRight->next;
                pairRight->next = pairLeft;
                prev = pairLeft;
                pairLeft = prev->next;
            }
            else
                break;
            
        }
        
        
        return head;
    }
};