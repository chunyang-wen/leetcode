/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// version 1: traverse
class Solution {
private:
    TreeNode *lastNode = NULL;
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (lastNode != NULL && lastNode->val >= root->val) {
            return false;
        }
        lastNode = root;
        return isValidBST(root->right);
    }
};

// traverse 2: divide & conquer
class ResultType {
public:
    bool isBST;
    TreeNode *maxNode, *minNode;
    ResultType() {
        this->isBST = true;
        this->maxNode = NULL;
        this->minNode = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        ResultType result = helper(root);
        return result.isBST;
    }
    
    ResultType helper(TreeNode *root) {
        ResultType result;
        if (root == NULL) {
            return result;
        }
        
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        
        if (!left.isBST || !right.isBST) {
            result.isBST = false;
            return result;
        }
        
        if (left.maxNode != NULL && left.maxNode->val >= root->val) {
            result.isBST = false;
            return result;
        }
        
        if (right.minNode != NULL && right.minNode->val val) {
            result.isBST = false;
            return result;
        }
        
        result.isBST = true;
        result.minNode = left.minNode == NULL ? root : left.minNode;
        result.maxNode = right.maxNode == NULL ? root : right.maxNode;
        return result;
    }
};
