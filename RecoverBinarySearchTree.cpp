// http://www.cnblogs.com/TenosDoIt/p/3445682.html
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
    void recoverTree(TreeNode *root) {
        //first,second 分别指向两个错误的节点，parent保存中序访问中当前节点的前驱
          TreeNode *first = NULL, *second = NULL, *parent = NULL;
          TreeNode *current = root, *pre = NULL;
          while(current != NULL)
          {                 
                if(current->left == NULL)
                {
                      if(parent != NULL)
                      {
                          if(first == NULL && current->val < parent->val)
                            first = parent;
                          else if(first && !second && current->val > first->val)
                            second = parent;
                      }
                      parent = current;
                      current = current->right;      
                }    
                else
                {
                      /* Find the inorder predecessor of current */
                      pre = current->left;
                      while(pre->right != NULL && pre->right != current)
                        pre = pre->right;
                        
                      if(pre->right == NULL)
                      {     /* Make current as right child of its inorder predecessor */
                            pre->right = current;
                            current = current->left;
                      }
                      else 
                      {
                            /* Revert the changes made in if part to restore the original 
                            tree i.e., fix the right child of predecssor */ 
                            //这里parent肯定不等于NULL
                            if(first == NULL && current->val < parent->val)
                                first = parent;
                            else if(first && !second && current->val > first->val)
                                second = parent;
                            parent = current;
                            
                            pre->right = NULL;
                            current = current->right;      
                      } 
                }
          } 
        if(first != NULL)
        {
            if(second == NULL)second = parent;//树{0,1}就可能出现这种情况
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
};