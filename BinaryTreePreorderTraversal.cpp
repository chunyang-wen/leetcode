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
    vector<int> preorderTraversal(TreeNode *root) {
        
        vector<int> res;
        if (root)
        {
            // preorderTraversalHelper(root, res);
            preorderTraversalHelperIterative(root, res);
        }
        return res;
    }
private:
    // recursive version
    void preorderTraversalHelper(TreeNode * node, vector<int> & res) {
        if (node)
        {
            res.push_back(node->val);
            preorderTraversalHelper(node->left, res);
            preorderTraversalHelper(node->right, res);
        }
    }
    
    // iterative version
    void preorderTraversalHelperIterative(TreeNode * root, vector<int> &res) {
        stack<TreeNode*> branches;
        branches.push(root);

        while (!branches.empty()) {
            TreeNode * node = branches.top();
            res.push_back(node->val);
            while (node->left)  {
                res.push_back(node->left->val);
                
                branches.push(node->left);
                node = node->left;
            }
            while (!node->right) {
                branches.pop();
                if (branches.empty()) {
                    return;
                }
                node = branches.top();
            }
            branches.pop();
            branches.push(node->right);
        }
    }
};