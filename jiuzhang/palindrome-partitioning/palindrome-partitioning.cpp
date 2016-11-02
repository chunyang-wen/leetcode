/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector>v;
    vectorv1;
    vector> partition(string s) {
        // write your code here
        v.clear();
        if(s.size()==0)return v;
        v1.clear();
        dfs(0,s);
        return v;         
    }
    bool ishui(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;j--;
            }
            else return false;
        }
        return true;
    }   
    void dfs(int depth,string s) {
        if(depth==s.size())
        {
            v.push_back(v1);
        }
        if(depth<s.size())
        {
            for(int i=depth;i<s.size();i++)
            {
                if(ishui(s.substr(depth,i-depth+1)))
                {
                    v1.push_back(s.substr(depth,i-depth+1));
                    dfs(i+1,s);
                    v1.pop_back();                   
                }
            }
        }
    }
};

