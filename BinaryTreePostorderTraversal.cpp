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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        
        postorderTraversalHelperNonRecursive(root,res);
        
        return res;
    }
private:
    void postorderTraversalHelper(TreeNode * node, vector<int> &res) {
        if (!node) 
            return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
            return;
        }
        postorderTraversalHelper(node->left,res);
        postorderTraversalHelper(node->right, res);
        res.push_back(node->val);
    }
    
    void postorderTraversalHelperNonRecursive(TreeNode * root, vector<int> &res) {
        
        if (!root)
            return;
        stack<TreeNode *> st;
        TreeNode * prevRight = NULL;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode * node = st.top();
            
            while (node->left) {
                st.push(node->left);
                node = node->left;
            }
            
            // now no left node
            
            while (!node->right || node->right == prevRight) {
                res.push_back(node->val);
                st.pop();
                
                if (st.empty())
                    return;
                
                if (st.top()->right == node) {
                    node = st.top();
                    prevRight = node->right;
                }
                else {
                    node = st.top();
                }
                
            }
            
            prevRight = node->right;
            st.push(node->right);
            
        }
        
        
        
    }
};