/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        long left = 0;
        if (x == 1)
            return 1;
        long right = x;
        long mid = left + (right-left)/2;
        while (left+1 < right) {
            if (x > mid*mid) {
                left = mid;
            } else if (x < mid*mid) {
                right = mid;
            } else {
                return mid;
            }
            mid = left + (right-left)/2;  
        }
        return left;
    }
};

