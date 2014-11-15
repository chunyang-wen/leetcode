/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int length = len(head);
        return sortedListToBSTHelper(head,0,length);
    }
private:
    TreeNode * sortedListToBSTHelper(ListNode *node, int start, int end) {
        if (start >= end || !node)
            return NULL;
        int mid = (end-start)/2 + start;
        ListNode *tmp = node;
        advance(tmp, mid-start);
        TreeNode *root = new TreeNode(tmp->val);
        TreeNode *left = sortedListToBSTHelper(node, start,mid);
        TreeNode *right = sortedListToBSTHelper(tmp->next, mid+1,end);
        root->left = left;
        root->right = right;
        return root;
        
    }
    int len(ListNode * node) {
        int length = 0;
        while(node) {
            ++length;
            node = node->next;
        }
        return length;
    }
    
    void advance(ListNode * &node, int length) {
        if (length <= 0)
            return;
        while (length--) {
            node = node->next;
        }
    }
};