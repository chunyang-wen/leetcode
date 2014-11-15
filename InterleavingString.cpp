// http://www.cnblogs.com/TenosDoIt/p/3448469.html
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 == 0)return s2 == s3;
        else if(len2 == 0)return s1 == s3;
        // dp[i][j]表示s1[0...i-1]和s2[0...j-1]能否组合成s3[0....i+j-1]
        bool dp[len1+1][len2+1];
        memset(dp, 0, sizeof(dp));
        if(len3 != 0)
        {
            if(s1[0] == s3[0])dp[1][0] = true;
            if(s2[0] == s3[0])dp[0][1] = true;
        }
        else return false;// len3 = 0,但是len1和len2不等于0
        if(len1 + len2 != len3)return false;//长度关系不满足
        for(int i = 0; i <= len1; i++)
            for(int j = 0; j <= len2; j++)
            {
                int tmp = i+j-1;
                if(j > 0)
                {
                    if(dp[i][j-1] && s3[tmp] == s2[j-1])
                        {dp[i][j] = true; continue;}
                }
                if(i > 0)
                {
                    if(dp[i-1][j] && s3[tmp] == s1[i-1]) 
                        dp[i][j] = true;
                }
            }
        if(dp[len1][len2])return true;
        else return false;
    }
};