// https://oj.leetcode.com/problems/balanced-binary-tree
//
// Height of left and right distance is less than 1
//

/**
 * Definition for binary tree
 * struct TreeNode {
 * 		int val;
 * 		TreeNode *left;
 * 		TreeNode *right;
 * 		TreeNode(int x):val(x),left(NULL),right(NULL){}
 * 	};
 */

class Solution {
	public:
		bool isBalanced(TreeNode *root) {
			if (!root)
				return true;
			int height = 0;
			return isBalancedHelper(root,height);
		}

	private:
		bool isBalancedHelper(TreeNode *node, int &cur) {
			if (!node)
				return true;
			if (!node->left && !node->right) {
				++cur;
				return true;
			}

			int leftHeight = cur+1;
			if (!isBalancedHelper(node->left,leftHeight)) 
				return false;

			int rightHeight = cur+1;

			if (!isBalancedHelper(node->right, rightHeight))
				return false;

			cur = leftHeight < rightHeight ? rightHeight:leftHeight;
			return (leftHeight-rightHeight >= -1) && (leftHeight-rightHeight <= 1);
		}
};
