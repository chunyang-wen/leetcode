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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector> levelOrder(TreeNode *root) {
        vector> result;
        if (root == NULL) {
            return result;
        }
        
        queue Q;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            vector level;
            
            for (int i = 0; i < size; i++) {
                TreeNode *head = Q.front(); Q.pop();
                level.push_back(head->val);
                if (head->left != NULL) {
                    Q.push(head->left);
                }
                if (head->right != NULL) {
                    Q.push(head->right);
                }
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};

