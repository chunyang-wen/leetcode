/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend >= 0 ? dividend : -(long long) dividend;
        long long b = divisor >= 0 ? divisor : -(long long) divisor;
        long long result = 0, shift = 31;
        while (shift >= 0) {
            if (a >= b << shift) {
                a -= b << shift;
                result += 1LL << shift;
            }
            shift--;
        }
        result = ((dividend ^ divisor) >> 31) ? (-result) : (result);
        if (result > INT32_MAX) return INT32_MAX;
        else return result;
    }
};
