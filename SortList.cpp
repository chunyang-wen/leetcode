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
    ListNode *sortList(ListNode *head) {
        // merge sort, bottom up sort
        return mergeSort(head, NULL);
    }
    
private:
    
    ListNode * mergeSort(ListNode *start, ListNode * end) {
        // merge sort, bottom up sort
        if (start == end || !start)
            return NULL;
        int size = 0;
        ListNode* cur = start;
        while (cur != end) {++size;cur = cur->next;}
        if (1 == size) {
			start->next = NULL;
            return start;
		}
        size>>=1;
        cur = start;
        while(size--) cur = cur->next;
        ListNode * left = mergeSort(start, cur);
        ListNode * right = mergeSort(cur, end);
        
        return merge(left, right);
    }

    ListNode * merge(ListNode * left,ListNode * right) {
        
        if (!left) return right;
        if (!right) return left;

        ListNode * head, *cur;
        
        if (left->val > right->val) {
            head = right;
            right = right->next;
        }
        else {
            head = left;
            left = left->next;
        }
        
        cur = head;
        ListNode * node;
        while ((left != NULL) && (right != NULL)) {
            if (left->val > right->val) {
				cur->next = right;
				cur = right;
				right = right->next;
            }
            else {
				cur->next = left;
				cur = left;
				left = left->next;
            }
        }
        

        
        if (!left) {
            node = right;
            while (node) {
            cur->next = node;
            cur = node;
            node = node->next;
        }
			// cur->next = end;
        }
        
        if (!right) {
            node = left;
            while (node) {
            cur->next = node;
            cur = node;
            node = node->next;
        }
			// cur->next = middle;
        }        

        return head;
        
    }
};