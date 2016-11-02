/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        bool interleave[s1.length() + 1][s2.length() + 1];
        interleave[0][0] = true;
        for (int i = 1; i <= s1.length(); i++) {
            interleave[i][0] = interleave[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= s2.length(); i++) {
            interleave[0][i] = interleave[0][i - 1] && s2[i - 1] == s3[i - 1];
        }
        
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                interleave[i][j] = false;
                if (s1[i - 1] == s3[i + j - 1]) {
                    interleave[i][j] = interleave[i][j] || interleave[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    interleave[i][j] = interleave[i][j] || interleave[i][j - 1];
                }
            }
        }
        
        return interleave[s1.length()][s2.length()];
     }
};

