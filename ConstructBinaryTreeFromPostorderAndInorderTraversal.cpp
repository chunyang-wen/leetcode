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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode * root = NULL;
        buildTreeHelper(root, inorder, 0, inorder.size(),postorder, 0, postorder.size());
        return root;
    }
private:
    void buildTreeHelper(TreeNode * &node, vector<int> & inorder, int start1, int end1, vector<int> &postorder, int start2, int end2) {
        
        if (start1 >= end1 || start2 >= end2)
            return;
        
        node = new TreeNode(postorder[end2-1]);
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        
        
        
        
        // inorder, find position of postorder[end2-1]
        int mid1 = 0;
        while (start1 < end1 && inorder[mid1] != postorder[end2-1]) {
            ++mid1;
        }
        
        buildTreeHelper(left,inorder,start1,mid1,postorder,start2,start2 + mid1-start1);
        buildTreeHelper(right,inorder,mid1+1,end1,postorder,start2 + mid1-start1,end2-1);
        
        node->left = left;
        node->right = right;
        
    }
};