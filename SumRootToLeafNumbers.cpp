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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        int num = 0;
        if (!root)
            return 0;
        num = 0;
        return sumNumbersHelper(root, num);
    }
    
private:
    int sumNumbersHelper(TreeNode * node, int num) {

        if (!node->left && !node->right)
            return num * 10 + node->val;
        int num1 = 0,num2 = 0;
        if (node->left)
            num1 = sumNumbersHelper(node->left, num * 10 + node->val);
        if (node->right)
            num2 = sumNumbersHelper(node->right, num * 10 + node->val);
        return num1 + num2;
    }
};