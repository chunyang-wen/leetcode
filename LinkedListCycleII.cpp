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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next ||!head->next->next)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        ListNode *prev = head->next;
        while(fast && slow != fast) {
            if (!fast->next)
                break;
            slow = slow->next;
            prev = fast->next;
            fast = fast->next->next;
        }
        
        if (!fast || !fast->next)
            return NULL;
            
        // fast == slow
        // break the list
        prev->next = NULL;
        
        // calculate each length
        int len1 = len(slow);
        int len2 = len(head);
        advance(slow, len1-len2);
        advance(head, len2-len1);
        
        while (slow != head) {
            slow = slow->next;
            head = head->next;
        }
        
        // restore the list
        prev->next = fast;
        return slow;
        
    }
private:
    int len(ListNode * node) {
        int length = 0;
        while (node) {
            ++length;
            node = node->next;
        }
        return length;
    }
    
    void advance(ListNode * &node, int len) {
        if (len <= 0) return;
        while (len--) {
            node = node->next;
        }
    }
};