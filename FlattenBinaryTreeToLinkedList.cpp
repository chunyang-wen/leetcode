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
	void flatten(TreeNode *root) {
		flattenHelper(root);
	}
private:
	TreeNode * flattenHelper(TreeNode *node) {
		if (!node)
			return NULL;
		// four kinds

		if (!node->left && !node->right) {
			return node;
		}

		if (!node->left) {
			return flattenHelper(node->right);
		}

		if (!node->right) {
			node->right = node->left;
			node->left = NULL;
			return flattenHelper(node->right);
		}

		TreeNode * left = flattenHelper(node->left);
		TreeNode * right = flattenHelper(node->right);
		TreeNode *tmp = node->right;
		node->right = node->left;
		node->left = NULL;
		left->right = tmp;
		return right;

	}
};