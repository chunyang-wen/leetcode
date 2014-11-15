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
	int maxPathSum(TreeNode *root) {
		if(!root)
			return 0;
		int curMax = INT_MIN;
		int sum = maxPathSumHelper(root, curMax);
		return max(sum,curMax);
	}
private:
	int maxPathSumHelper(TreeNode * node, int &curMax) {
		if (!node)
			return INT_MIN;

		int cur = node->val;

		int left = maxPathSumHelper(node->left,curMax);
		int right = maxPathSumHelper(node->right,curMax);

		int maxSubTree = (left < right?right:left);

		// get max of 
		// any sub tree and current node
		// left-node-right
		// return cur + maxSubTree

		if (node->val > curMax) curMax = node->val;
		if (left > curMax) curMax = left;
		if (right > curMax) curMax = right;

		if (node->left)
			cur += left;
		if (node->right)
			cur += right;
		if (cur > curMax) curMax = cur;

		cur = node->val;
		if (maxSubTree > 0)
			cur += maxSubTree;

		return cur;

	}
};