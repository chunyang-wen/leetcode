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
	ListNode *partition(ListNode *head, int x) {

		if (!head || !head->next)
			return head;

		ListNode * less = new ListNode(0);
		ListNode * great = new ListNode(0);
		ListNode * lessStart = less;
		ListNode * greatStart = great;
		while (head) {
			if (head->val < x) {
				less->next = head;
				less = less->next;
				// less->next = NULL;
			}
			else {
				great->next = head;
				great = great->next;
				// great->next = NULL;
			}
			head = head->next;
		}

		if (lessStart->next) {
			head = lessStart->next;
			less->next = greatStart->next;
			great->next = NULL;
		}
		else {
			head = greatStart->next;
			great->next = NULL;
		}

		delete lessStart;
		delete greatStart;

		return head;
	}
};