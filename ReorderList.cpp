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
	void reorderList(ListNode *head) {
		int length = len(head);
		if (length < 3)
			return;
		int mid = (length-1)/2;
		ListNode * right = head;
		advance(right, mid);

		ListNode * left = right->next;
		right->next = NULL;
		right = reverse(left,mid+1,length);
		left = head;
		connect(left, right);
		
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

	void advance(ListNode * &node, int k) {
		while (node && k--) {
			node = node->next;
		}
	}

	ListNode * reverse(ListNode * node, int start, int end) {
		ListNode * prev = node;
		ListNode * next = node->next;
		ListNode * temp = node;
		ListNode * head = node;
		while (next && start < end) {
			temp = next->next;
			next->next = prev;
			prev = next;
			next = temp;
			++start;
		}
		head->next = next;
		head = prev;
		return head;
	}

	ListNode * connect(ListNode * left, ListNode *right) {
		ListNode * head;
		if (left)
			head = left;
		else
			return right;
		ListNode * leftNext;
		ListNode * rightNext;
		while (left && right) {
			leftNext = left->next;
			rightNext = right->next;
			left->next = right;
			right->next = leftNext;
			left = leftNext;
			right = rightNext;
		}
		return head;
	}
};