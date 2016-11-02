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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector generate(int beg, int end)
    {
        vector ret;
        if (beg > end)
        {
            ret.push_back(NULL);
            return ret;
        }
        
        for(int i = beg; i <= end; i++)
        {
            vector leftTree = generate(beg, i - 1);
            vector rightTree = generate(i + 1, end);
            for(int j = 0; j < leftTree.size(); j++)
                for(int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode *node = new TreeNode(i + 1);
                    ret.push_back(node);
                    node->left = leftTree[j];
                    node->right = rightTree[k];              
                }           
        }
        
        return ret;
    }
    vector generateTrees(int n) {
        // write your code here
        return generate(0,n-1);
    }
};

