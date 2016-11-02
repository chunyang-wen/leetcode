/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include 
#include "lintcode.h"
#include 
#include 
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
 
 
class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector > ret;
		ret.clear();
		if(root == NULL)
			return ret;
		queue S;
		S.push(root);
		S.push(NULL);
		vector tmp;
		while(!S.empty()){
			//travesal current level
			TreeNode* p = S.front();
			S.pop();
			if(p!=NULL)
			{
				tmp.push_back(p->val);
				if(p->left) 
					S.push(p->left);
				if(p->right)
					S.push(p->right);
			}else{
				if(!tmp.empty())
				{	
					S.push(NULL);
					ret.push_back(tmp);
					tmp.clear();
				}
			}
		}
		reverse(ret.begin(),ret.end());
        return ret;
    }
};

