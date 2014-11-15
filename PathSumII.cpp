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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> cur;
        
        pathSumHelper(root, res,cur, sum);
        
        return res;
    }
private:
    void pathSumHelper(TreeNode * node, vector<vector<int> > &res, vector<int> &cur, int sum) {
        if (!node)
            return;
        if (!node->left && !node->right) {
            sum -= node->val;
            if(!sum) {
                cur.push_back(node->val);
                res.push_back(cur);
                cur.pop_back();
            }
            return;
            
        }
        
        if (node->left) {
            
            sum -= node->val;
            if (true) {
                cur.push_back(node->val);
                pathSumHelper(node->left, res, cur, sum);
                cur.pop_back();
            }
            
            sum += node->val;
        }
        
        if (node->right) {
            
            sum -= node->val;
            if (true) {
                cur.push_back(node->val);
                pathSumHelper(node->right, res, cur, sum);
                cur.pop_back();
            }
            sum += node->val;
        }
        
        
        
    }
};