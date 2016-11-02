/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int search(TreeNode * root, int now) {
        if (root->left==NULL && root->right==NULL){
            return now==1? root->val: 0;
        }
        int sum = 0;
        if (root->left!=NULL)
            sum += search(root->left, 1);
        if (root->right!=NULL)
            sum += search(root->right, 0);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (root != NULL) {
            return search(root, 0);
        }
        return 0;
    }
};
