/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        vector> t(T.length()+1,vector<int>(S.length()+1));
        for(int i=0;i<=T.length();i++) t[i][0]=0;
        for(int i=0;i<=S.length();i++) t[0][i]=0;
        for(int i=1;i<=S.length();i++)
        {
            if(T[0]==S[i-1])
                t[1][i]=t[1][i-1]+1;
            else
                t[1][i]=t[1][i-1];    
        }
        
        
        for(int i=2;i<=T.length();i++)
        {
            for(int j=1; j<=S.length();j++)
            {
                if(T[i-1]==S[j-1])
                    t[i][j]=t[i-1][j-1]+t[i][j-1];
                else
                    t[i][j]=t[i][j-1];
            }
        }
        return t[T.length()][S.length()];
    }
};


