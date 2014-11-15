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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root) {
            stack<TreeNode *> branches;
            branches.push(root);
            while (!branches.empty()) {
                
                TreeNode * node = branches.top();
                
                // left until leaf
                while (node->left) {
                    branches.push(node->left);
                    node = node->left;
                }
                
                res.push_back(node->val);
                while (!node->right) {
                    branches.pop();
                    if (branches.empty())
                        return res;
                    node = branches.top();
                    res.push_back(node->val);
                }
                branches.pop();
                branches.push(node->right);
            }
        }
    }
};