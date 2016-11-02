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
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) {
            return false;
        }
        
        int n = strlen(s);
        int m = strlen(p);
        int f[n + 1][m + 1];
        
        memset(f, false, sizeof(f));
        
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
            f[i][0] = false;
        
        for (int i = 1; i <= m; i++)
            f[0][i] = f[0][i - 1] && p[i - 1] == "*";
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == "*") {
                    f[i][j] = f[i - 1][j] || f[i][j - 1];
                } else if (p[j - 1] == "?") {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        } // for
        
        return f[n][m];
    }
};

