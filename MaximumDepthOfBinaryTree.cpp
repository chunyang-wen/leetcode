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
    int maxDepth(TreeNode *root) {
        int depth = 0;
        return maxDepthHelper(root, depth);
    }
private:
    int maxDepthHelper(TreeNode *node, int depth)
    {
        if (!node)
            return depth;
        ++depth;
        int leftDepth = maxDepthHelper(node->left, depth);
        int rightDepth = maxDepthHelper(node->right, depth);
        return leftDepth>rightDepth? leftDepth:rightDepth;
    }
};