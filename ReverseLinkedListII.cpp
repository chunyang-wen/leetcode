class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {

		if (m == n || !head || !head->next)
			return head;

		ListNode *start, *end;
		ListNode * cur = head;

		m -= 2;
		--n;
		while (m-->0) {
			cur = cur->next;
		}

		start = cur;

		cur = head;

		while (n--) {
			cur = cur->next;
		}
		end = cur;

		// reverse start and end;
		if (start == head && m == -2) {// head will change
			head = end;
		}
		else {
			// we try to reverse directly
			cur = start->next;
			start->next = end;	
			start = cur;	
		}

		ListNode * prev = end->next;
		end = end->next;
		while (start != end) {
			// reverse start and prev
			cur = start->next;
			start->next = prev;
			prev = start;
			start = cur;
		}

		return head;
	}
};