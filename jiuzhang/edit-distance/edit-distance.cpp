/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int row = word1.length() + 1;
        int col = word2.length() + 1;
        vector > f(row, vector<int>(col));
        for (int i = 0; i < row; i++)
            f[i][0] = i;
        for (int i = 0; i < col; i++)
            f[0][i] = i;
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++){
                if (word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = f[i-1][j-1] + 1;
                f[i][j] = min(f[i][j], min(f[i-1][j]+1, f[i][j-1]+1));
            }

        return f[row-1][col-1];
    }
};


