class Solution {
public:
    bool isScramble(string s1, string s2) {
        //动态规划解法
        if(s1.size() != s2.size())return false;
        const int len = s1.size();
        //dp[k][i][j]表示s2从j开始长度为k的子串是否可以由s1从i开始长度为k的子串转换而成
        bool dp[len+1][len][len];
        //初始化长度为1的子串的dp值
        for(int i = 0; i <= len-1; i++)
            for(int j = 0; j <= len-1; j++)
                dp[1][i][j] = s1[i] == s2[j] ? true : false;
        for(int k = 2; k <= len; k++)//子串的长度
            for(int i = 0; i <= len-k; i++)//s1的起始位置
                for(int j = 0; j <= len-k; j++)//s2的起始位置
                {
                    dp[k][i][j] = false;
                    //divlen表示两个子串分割点到子串起始端的距离
                    for(int divlen = 1; divlen < k && !dp[k][i][j]; divlen++)
                        dp[k][i][j] = (dp[divlen][i][j] && dp[k-divlen][i+divlen][j+divlen])
                            || (dp[divlen][i][j+k-divlen] && dp[k-divlen][i+divlen][j]);
                }
        return dp[len][0][0];
    }
};