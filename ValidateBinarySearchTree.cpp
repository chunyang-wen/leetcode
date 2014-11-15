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
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;
        stack<TreeNode *> st;
        st.push(root);
        
        TreeNode *node;
        
        vector<int> res;
        
        while (!st.empty()) {
            
            node = st.top();
            
            while (node->left) {
                st.push(node->left);
                node = node->left;
            }
            res.push_back(node->val);
            while (!node->right) {
                st.pop();
                if (st.empty()) {
                    // start test
                    for (int i = 0; i < res.size()-1; ++i) {
                        if (res[i] >= res[i+1])
                            return false;
                    }
                    return true;
                };
                node = st.top();
                res.push_back(node->val);
            }
            st.pop();
            st.push(node->right);
        }
        return true;
    }
};