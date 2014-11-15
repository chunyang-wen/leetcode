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
    int minDepth(TreeNode *root) {
        int val = 0;
        int depth = INT_MAX;
        if (!root)
            return 0;
        minDepthHelper(root,val,depth);
        return depth;
    }
private:
    void minDepthHelper(TreeNode * node, int val, int &depth) {
        if (!node) 
            return;
        if (!node->left && !node->right) {
            if (val + 1 < depth)
                depth = val + 1;
        }
        if (node->left) {
            minDepthHelper(node->left, val + 1, depth);
        }
        
        if (node->right) {
            minDepthHelper(node->right, val + 1, depth);
        }
        
    }
};