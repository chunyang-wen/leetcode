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
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head)
			return head;

		ListNode ** cur = &head;
		ListNode * node;
		ListNode * tmp, * prev;

		bool hasDuplicates = false;

		while (*cur) {

			node = *cur;

			if (!node->next)
				break;

			tmp = node->next;

			while (tmp && (node->val == tmp->val)) {
				prev = tmp->next;
				// delete tmp;
				tmp = prev;
				hasDuplicates = true;
			}
			if (hasDuplicates) {
				hasDuplicates = false;
				// delete current node
				*cur = tmp;

				if (node == head) {
					head = tmp;
				}

				// delete tmp;
			}
			else {
				cur = &(node->next);
			}


		}

		return head;



	}
};