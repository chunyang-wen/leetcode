/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector A) {
        // write your code here
        long long result = 0;
        long long f = 0, g = 0, f1 = 0, g1 = 0;
        int len = A.size();
        for (int i = 0; i < len; ++i) {
            f1 = g + A[i];
            g1 = max(f, g);
            g = g1, f = f1;        
        }
        return max(g, f);
    }
};
