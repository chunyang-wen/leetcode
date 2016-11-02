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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
private:
    void visit(TreeNode* root, int &rob, int &not_rob) {
        rob = not_rob = 0;
        if (root == NULL)
            return;
            
        int left_rob, left_not_rob, right_rob, right_not_rob;
        visit(root->left, left_rob, left_not_rob);
        visit(root->right, right_rob, right_not_rob);
        
        rob = left_not_rob + right_not_rob + root->val;
        not_rob = max(left_rob, left_not_rob) + max(right_rob, right_not_rob);
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        int rob, not_rob;
        visit(root, rob, not_rob);
        return max(rob, not_rob);
    }
};

