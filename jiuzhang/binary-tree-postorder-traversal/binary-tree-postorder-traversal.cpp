/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// non-recursion version 

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
    vector postorderTraversal(TreeNode *root) {
        vector result;
        stack myStack;
        
        TreeNode *current = root, *lastVisited = NULL;
        while (current != NULL || !myStack.empty()) {
            while (current != NULL) {
                myStack.push(current);
                current = current->left;
            }
            current = myStack.top(); 
            if (current->right == NULL || current->right == lastVisited) {
                myStack.pop();
                result.push_back(current->val);
                lastVisited = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }
        return result;
    }
};
