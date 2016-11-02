/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include 
#include 
#include 
#include "lintcode.h"

using namespace std;

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
 
struct Node
{
    TreeNode *node;
    int level;
    Node(){}
    Node(TreeNode *n, int l):node(n), level(l){}
}; 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes" values 
     */
public:
    vector> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector > ret;
		ret.clear();       
        if (root == NULL)
            return ret;        
        queue q;        
        q.push(Node(root, 0));        
        int curLevel = -1;        
        vector a;        
        while(!q.empty())
        {
            Node node = q.front();            
            if (node.node->left)
                q.push(Node(node.node->left, node.level + 1));           
            if (node.node->right)
                q.push(Node(node.node->right, node.level + 1));   
            if (curLevel != node.level)
            {
                if (curLevel != -1)
                {
                    if (curLevel % 2 == 1)
                        reverse(a.begin(), a.end());
                        
                    ret.push_back(a);
                }
                a.clear();
                curLevel = node.level;
            }
            a.push_back(node.node->val);
            q.pop();
        }        
        if (curLevel % 2 == 1)
            reverse(a.begin(), a.end());   
        ret.push_back(a);
        return ret;
    }
};

