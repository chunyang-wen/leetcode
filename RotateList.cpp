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
    ListNode *rotateRight(ListNode *head, int k) {
        int len=0;
        if(!head || !k) return head;
        ListNode * cur= head;
        while (cur) {
            ++len;
            cur=cur->next;
        }
    if(k >= len)
        k %= len;
        
        if (k) {
            ListNode * slow = head;
            ListNode * fast = head;
            while (k--) {
                fast = fast->next;
            }
            
            while (fast->next) {
                slow = slow->next;fast=fast->next;
            };
    //      cur = head  
            fast->next = head;head = slow->next; slow->next=NULL;
        
        }
return head;
    }
    
};