/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if (s.size() == 0)
            return 0;
        else if (s.size() == 1)
            return s[0] != "0" ? 1 : 0;  
          
        int* dp = new int[s.size()];  
        dp[0] = s[0] != "0" ? 1 : 0;  
        dp[1] = (s[0] != "0" && s[1] != "0"? 1 : 0) +
        ((s[0] != "0" && (toInt(s[0]) * 10 + toInt(s[1])) <= 26) ? 1 : 0);  
          
        for (int i = 2; i < s.size(); ++i) {  
            dp[i] = 0;  
            if(s[i] != "0")
                dp[i] += dp[i-1];
            if(s[i-1] != "0" && (toInt(s[i-1]) * 10 + toInt(s[i])) <= 26){  
                dp[i] += dp[i-2];  
            }  
        }  
          
        return dp[s.size() - 1];  
    }

    int toInt(char c){  
        return c - "0";
    }
};

