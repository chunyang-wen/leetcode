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
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (k == 1)
			return head;
		int length = len(head);
		if (length < k)
			return head;
		ListNode * node = head;
		head = reverse(node, k);
		node->next = reverseKGroup(node->next,k);
		return head;

	}

private:
	int len(ListNode * node) {
		int length = 0;
		while(node) {
			++length;
			node = node->next;
		}
		return length;
	}

	ListNode * reverse(ListNode * (&node), int k) {
		if (!node)
			return NULL;
		ListNode * prev = node;
		ListNode * next = node->next;
		ListNode * cur = node;
		ListNode * start = node;
		k = k-1;
		while (k-- && next) {
			cur = next->next;
			next->next = prev;
			prev = next;
			next = cur;
		}
		start->next = next;
		node = start;
		return prev;
	}
};