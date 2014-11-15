// http://www.cnblogs.com/TenosDoIt/p/3448569.html
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
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<vector<TreeNode*> > > btrees(n+2, vector<vector<TreeNode*> >(n+2, vector<TreeNode*>()));
        for(int i = 1; i <= n+1; i++)
            btrees[i][i-1].push_back(NULL); //为了下面处理btrees[i][j]时 i > j的边界情况
        for(int k = 1; k <= n; k++)//k表示节点数目
            for(int i = 1; i <= n-k+1; i++)//i表示起始节点
            {
                for(int rootval = i; rootval <= k+i-1; rootval++)
                {//求[i,i+1,...i+k-1]序列对应的所有BST树
                    for(int m = 0; m < btrees[i][rootval-1].size(); m++)//左子树
                        for(int n = 0; n < btrees[rootval+1][k+i-1].size(); n++)//右子树
                        {
                            TreeNode *root = new TreeNode(rootval);
                            root->left = btrees[i][rootval-1][m];
                            root->right = btrees[rootval+1][k+i-1][n];
                            btrees[i][k+i-1].push_back(root);
                        }
                }
            }
        return btrees[1][n];
    }
};