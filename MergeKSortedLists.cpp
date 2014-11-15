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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return NULL;
        
		ListNode *head = NULL;
		ListNode *start;
        auto prevEnd = remove_if(lists.begin(),lists.end(),IsNull());
		lists.erase(prevEnd,lists.end());
		int len = lists.size();
		priority_queue<ListNode*, vector<ListNode*>, CMP> pq;
		for (int i = 0; i<len;++i) {
			pq.push(lists[i]);
		}
		ListNode * node;
		while (!pq.empty()) {
			node = pq.top();
			if (!head) {
				head = node;
				start = head;
			}
			else {
				start->next = node;
				start = start->next;
			}
			pq.pop();
			if (node->next)
				pq.push(node->next);
		}
        return head;
    }
private:
    struct CMP {
      bool operator()(const ListNode* left, const ListNode * right) {
          return left->val > right->val;
      }  
    };
    
    struct IsNull {
        bool operator()(ListNode *node) {
			return !node;
		}
    };
    ListNode *merge2Lists(ListNode * left, ListNode *right) {
        if (!left)
            return right;
        if (!right)
            return left;
        
        ListNode *head, *start;
        if (left->val > right->val) {
            head = right;
            right = right->next;
        }
        else {
            head = left;
            left = left->next;
        }
        start = head;
        while (left && right) {
            if (left->val > right->val) {
                start->next = right;
                right = right->next;
            }
            else {
                start->next = left;
                left = left->next;
            }
            start = start->next;
        }
        
        if (left) {
            start->next = left;
        }
        if (right) {
            start->next = right;
        }
        return head;
        
    }
};