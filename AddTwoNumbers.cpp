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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode * head = NULL;
        ListNode * cur = l1;
        int carry = 0;
        while (l1 && l2) {
            l1->val += (l2->val+carry);
            carry = l1->val/10;
            l1->val %= 10;

			if (!head) {
				head = l1;
				cur = l1;
			}
			else {
				cur->next = l1;
				cur = cur->next;
			}

            l1 = l1->next;
            l2 = l2->next;
            
        }
        
        while (l1 && carry) {
            l1->val += carry;
            carry = l1->val/10;
            l1->val %= 10;
			cur->next = l1;
            l1 = l1->next;            
            cur = cur->next;
        }
        
        while(l2) {
            
            if (!carry) {
                cur->next = l2;
                break;
            }
            
            l2->val += (carry);
            carry = l2->val/10;
            l2->val %= 10;
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        
        while (carry) {
            ListNode * car = (ListNode *)malloc(sizeof(ListNode));
            car->val = carry%10;
            car->next = NULL;
            carry = carry/10;
            cur->next = car;
            cur = cur->next;
            
        }
        
        return head;
        
    }
};