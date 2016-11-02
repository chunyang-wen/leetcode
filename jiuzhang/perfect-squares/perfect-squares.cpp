/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// version 1
class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        vector dp{ 0 };
        dp.resize(n + 1, INT_MAX);
        for (int i = 1, k; (k = i * i) <= n; ++i)
            for (int j = k; j <= n; ++j)
                if (dp[j] > dp[j - k] + 1)
                    dp[j] = dp[j - k] + 1;
        return dp[n];
    }
};


// version 2 Math
class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        int ub = sqrt(n);
        for (int a = 0; a <= ub; ++a) {
            for (int b = a; b <= ub; ++b) {
            int c = sqrt(n - a * a - b * b);
                if (a * a + b * b + c * c == n)
                    return !!a + !!b + !!c;
            }
        }
        return 4;
    }
};

// version 3 Math II
class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        for (int i = 0; i * i <= n; ++i) {
            int j = sqrt(n - i * i);
            if (i * i + j * j == n)
                return !!i + !!j;
        }
        return 3;
    }
};

