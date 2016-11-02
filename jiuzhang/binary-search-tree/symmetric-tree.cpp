// https://oj.leetcode.com/problems/symmetric-tree

// normal a bst problem can be solved using 
// recursive method.

// The problme asks us to test whether two tree is the same.


/**
  * Definition for binary tree
  * struct TreeNode {
  *		int val;
  * 	TreeNode *left;
  * 	TreeNode *right;
  * 	TreeNode(int x):val(x),left(NULL), right(NULL){}
  * };
  */

class Solution {
	public:
		bool isSymmetric(TreeNode *root) {
			if (!root)
				return true;
			return isSymmetricHelper(root->left, root->right);
		}

	private:
		bool isSymmetricHelper1(TreeNode *left, TreeNode *right) {
			if (!left && !right)
				return true;
			if ((!left && right) || (left && !right) ||(left->val != right->val)) 
				return false;
			return isSymmetricHelper1(left->left, left->right) &&
				isSymmetricHelper1(right-left,right->right);
		}

		bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
			// we do a inroder traversal
			// be aware left and right sub tree traverse in different
			// direction.

			stack<TreeNode *> leftSubTree;
			stack<TreeNode *> rightSubTree;

			leftSubTree.push(left);
			rightSubTree.push(right);

			while (!leftSubTree.empty() && !rightSubTree.empty() && leftSubTree.size() == rightSubTree.size()) {

				TreeNode * leftTop = leftSubTree.top();
				TreeNode * rightTop = rightSubTree.top();

				if (!leftTop && !rightTop)
					return true;

				if ((!leftTop && rightTop) || (leftTop && !rightTop) || (leftTop->val != rightTop->val)) 
					return false;

				while (leftTop->left && rightTop->right) {
					if (leftTop->left->val != rightTop->right->val) 
						return false;

					leftSubTree.push(leftTop->left);
					rightSubTree.push(rightTop->right);

					leftTop = leftTop->left;
					rightTop = rightTop->right;
				}


				if (leftTop->left || rightTop->right)
					return false;

				while (!leftTop->right) {
					leftSubTree.pop();
					if (leftSubTree.empty())
						break;
					leftTop = leftSubTree.top();
				}

				while (!rightTop->left) {
					rightSubTree.pop();
					if (rightSubTree.empty())
						break;
					rightTop = rightSubTree.top();
				}

				if (leftTop->right) {
					leftSubTree.pop();
					leftSubTree.push(leftTop->right);
				}

				if (rightTop->left) {
					rightSubTree.pop();
					rightSubTree.push(rightTop->left);
				}
			}

			if (leftSubTree.emtpy() && rightSubTree.empty()) 
				return true;
			return false;
		}
};
