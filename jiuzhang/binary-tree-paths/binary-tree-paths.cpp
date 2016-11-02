/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector path;
        if(root == NULL)
            return path;
        vector > pathv;    
        unordered_map visited;
        stack stk;
        stk.push(root);
        visited[root] = true;
        if(root->left == NULL && root->right == NULL)
            save(pathv, stk);
        while(!stk.empty())
        {
            TreeNode* top = stk.top();
            if(top->left && visited[top->left] == false)
            {
                stk.push(top->left);
                visited[top->left] = true;
                if(top->left->left == NULL && top->left->right == NULL)
                    save(pathv, stk);
                continue;
            }
            if(top->right && visited[top->right] == false)
            {
                stk.push(top->right);
                visited[top->right] = true;
                if(top->right->left == NULL && top->right->right == NULL)
                    save(pathv, stk);
                continue;
            }
            stk.pop();
        }
        return convert(pathv);
    }

    void save(vector >& pathv, stack<TreeNode*> stk)
    {
        vector cur;
        while(!stk.empty())
        {
            TreeNode* top = stk.top();
            cur.push_back(top->val);
            stk.pop();
        }
        reverse(cur.begin(), cur.end());
        pathv.push_back(cur);
    }

    vector convert(vector<vector<int> >& pathv)
    {
        vector path;
        for(int i = 0; i < pathv.size(); i ++)
        {
            string cur;
            cur += to_string(pathv[i][0]);
            for(int j = 1; j < pathv[i].size(); j ++)
            {
                cur += "->";
                cur += to_string(pathv[i][j]);
            }
            path.push_back(cur);
        }
        return path;
    }
};
