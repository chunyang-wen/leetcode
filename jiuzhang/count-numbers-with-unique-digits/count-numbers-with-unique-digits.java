/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

//  solution 1
//DP Solution
public class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        if (n > 10) {
            n = 10;
        }
        //f[i]表示不含0的i位数中满足条件的数的个数
        //g[i]表示含有0的i位数中满足条件的数的个数
        int[] f = new int[11];
        int[] g = new int[11];
        int ans = 10;
        g[0] = 1;
        g[1] = 9;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i-1] * (11 - i) + g[i-2] * (11 - i);
            g[i] = g[i-1] * (10 - i);
            ans += f[i] + g[i];
        }
        return ans;
    }
}

// solution 2
//Math Method
public class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n > 10) {
            n = 10;
        }
        int ans = 1;
        int multiple = 9;
        for (int i = n - 1; i >= 0; i--) {
            if (i == 0) {
                ans += multiple;
            } else {
                ans += (n - i + 1) * multiple;
            }
            multiple = multiple * (10 - n + i - 1);
        }
        return ans;
    } 
}
