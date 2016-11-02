/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector generateParenthesis(int n) {
        // Write your code here
        vector res;
        string s;
        helper(s,res,0,0,n);
        return res;
    }
    void helper(string s,vector &res,int l,int r,int n){
        if(r==n){
            res.push_back(s);
        }
        else if(l==n){
            s+=")";
            helper(s,res,l,r+1,n);
        }
        else{
            if(l>r)
                helper(s+")",res,l,r+1,n);
            helper(s+"(",res,l+1,r,n);
        }
    }
};
