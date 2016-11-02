/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack myStack;
    TreeNode *current;
    
    BSTIterator(TreeNode *root) {
        while (!myStack.empty()) {
            myStack.pop();
        }
        current = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (current != NULL || !myStack.empty());
    }

    /** @return the next smallest number */
    TreeNode* next() {
        while (current != NULL) {
            myStack.push(current);
            current = current->left;
        }
        current = myStack.top(); myStack.pop();
        TreeNode *nxt = current;
        current = current->right;
        return nxt;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
