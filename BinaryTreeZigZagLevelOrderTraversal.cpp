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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        
        vector<vector<int> > res;
        
        if (!root)
            return res;
        
        deque<TreeNode *> curLevel;
        deque<TreeNode *> nextLevel;
        vector<int> levelVector;
        curLevel.push_back(root);
        TreeNode * node;
        
        int cnt = 1;
        
        while (!curLevel.empty()) {
            
            nextLevel.clear();
            levelVector.clear();
            
            while (!curLevel.empty()) {
                node = curLevel.front();
                curLevel.pop_front();
                if (node->left) {
                    nextLevel.push_back(node->left);
                }
                if (node->right) {
                    nextLevel.push_back(node->right);
                }
                levelVector.push_back(node->val);
            }
            
            if (!(cnt&0x1)) {
                reverse(levelVector.begin(),levelVector.end());
            }
            ++cnt;
            
            res.push_back(levelVector);
            
            if (nextLevel.empty())
                break;
            
            curLevel = nextLevel;
            
        }
        
        
        
        return res;
        
    }
};