/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root) {
            connectHelper(root);
        }
    }
private:
    void connectHelper(TreeLinkNode *node) {
        if (!node || (!node->left && !node->right)) 
            return;
        // if has left and right child, connect
        node->left->next = node->right;
        if (node->next) {
            node->right->next = node->next->left;
        }
        connectHelper(node->left);
        connectHelper(node->right);
        
    }
};