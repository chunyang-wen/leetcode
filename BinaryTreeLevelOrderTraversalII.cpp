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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        
        vector<vector<int> > res;
        if (!root)
            return res;
        deque<TreeNode *> stk;
        deque<TreeNode *> stkNextLevel;
        stk.push_back(root);
        vector<int> curLevel;
        curLevel.push_back(root->val);
        res.push_back(curLevel);
        
        if(!root->left && !root->right)
            return res;
        
        TreeNode * curNode;
        while(!stk.empty()) {
            curLevel.clear();
            stkNextLevel = deque<TreeNode*>();
            while(!stk.empty()) {
                curNode = stk.front();
                stk.pop_front();
                if (curNode->left) {
                    curLevel.push_back(curNode->left->val);
                    stkNextLevel.push_back(curNode->left);
                }
                if (curNode->right) {
                    curLevel.push_back(curNode->right->val);
                    stkNextLevel.push_back(curNode->right);
                }
            }
            
            if(stkNextLevel.empty())
                break;
            
            res.push_back(curLevel);
            stk=stkNextLevel;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};