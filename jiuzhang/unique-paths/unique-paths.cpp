/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector > f(m, vector<int>(n));
        
        for(int i = 0; i < n; i++)
            f[0][i] = 1;
            
        for(int i = 0; i < m; i++)
            f[i][0] = 1;
            
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                f[i][j] = f[i-1][j] + f[i][j-1];
                
        return f[m-1][n-1];
    }
};


