/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param n: an integer
     * @return: an integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n <= 2)
            return n;
        int* step = new int[n];
        step[0] = 1;
        step[1] = 2; 
        for(int i = 2; i < n; i++) {
            step[i] = step[i-1] + step[i-2];
        }
        return step[n-1];
    }
};


