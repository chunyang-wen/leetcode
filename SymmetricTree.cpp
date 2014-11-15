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
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return isSymmetricHelper(root->left, root->right);
    }
    
private:
    bool isSymmetricHelper1(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if ((!left && right) || (left && !right) || left->val != right->val)
            return false;
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
        
    }
    
    bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
        
        stack<TreeNode *> leftSubTree;
        stack<TreeNode *> rightSubTree;
        leftSubTree.push(left);
        rightSubTree.push(right);
        
        while(!leftSubTree.empty() && !rightSubTree.empty() && leftSubTree.size() == rightSubTree.size()) {
            
            TreeNode * leftTop = leftSubTree.top(); 
            TreeNode * rightTop = rightSubTree.top();

            
            if (!leftTop && !rightTop)
                return true;
            if ((!leftTop && rightTop) || (leftTop && !rightTop) || leftTop->val != rightTop->val)
                return false;
                

            // leftSubTree, left, right head;

            while (leftTop->left && rightTop->right) {
                
                if (leftTop->left->val != rightTop->right->val)
                    return false;
                
                rightSubTree.push(rightTop->right);
                rightTop = rightTop->right;
                leftSubTree.push(leftTop->left);
                leftTop = leftTop->left;
            }
            
            if (leftTop->left || rightTop->right)
				return false;
            

            while (!leftTop->right) {

				leftSubTree.pop();		

				if(leftSubTree.empty())
					break;
				leftTop = leftSubTree.top();

				
				
			}
			
			while ( !rightTop->left) {
			    rightSubTree.pop();
				if(rightSubTree.empty())
					break;
				rightTop = rightSubTree.top();
			}
            
            if (leftSubTree.size() != rightSubTree.size())
				return false;

			if (leftSubTree.empty())
				return true;
				
            
            if (leftTop->right) {
                leftSubTree.pop();
                leftSubTree.push(leftTop->right);
            }
                
            if (rightTop->left) {
                rightSubTree.pop();
                rightSubTree.push(rightTop->left);
            }
                
            
        }
        
        if (leftSubTree.empty() && rightSubTree.empty()) {
            return true;
        }
        return false;
        
    }
    
};