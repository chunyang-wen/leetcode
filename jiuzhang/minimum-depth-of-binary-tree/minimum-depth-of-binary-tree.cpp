/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int ans;
    int solve_dp(TreeNode *root) {
        if(root == NULL)
            return 0;   

        if (root->left == NULL && root->right == NULL)
            return 1;
 
        int lf = 0x7fffffff, rt = 0x7fffffff;
        if(root->left)
            lf = solve_dp(root->left);
         
        if(root->right) 
            rt = solve_dp(root->right);

        return min(lf, rt) + 1;
    }
    int minDepth(TreeNode *root) {
        // write your code here
        if (!root) return 0;
        return solve_dp(root);
    }
};

