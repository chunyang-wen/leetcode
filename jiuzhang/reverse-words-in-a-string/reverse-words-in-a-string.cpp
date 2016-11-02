/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include 
#include 

using namespace std;

class Solution {
    /**
     * @param s : A string
     * @return : A string
     */
public:
    string reverseWords(string s) {
        string ss;
        int i = s.length()-1;
        while(i>=0)
        {
            while(i>=0&&s[i] == " ")
            {
                i --;
            }
            if(i<0) break;
            if(ss.length()!=0)
                ss.push_back(" ");
            string temp ;
            for(;i>=0&&s[i]!=" ";i--)
                temp.push_back(s[i]);
            reverse(temp.begin(),temp.end());
            ss.append(temp);
        }
        s=ss;
        return s;
    }
};

