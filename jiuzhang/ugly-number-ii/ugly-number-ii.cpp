/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        int *uglys = new int[n];
        uglys[0] = 1;
        int next = 1;
        int *p2 = uglys;
        int *p3 = uglys;
        int *p5 = uglys;
        while (next < n){
            int m = min(min(*p2 * 2, *p3 * 3), *p5 * 5);
            uglys[next] = m;
            while (*p2 * 2 <= uglys[next])
                *p2++;
            while (*p3 * 3 <= uglys[next])
                *p3++;
            while (*p5 * 5 <= uglys[next])
                *p5++;
            next++;
        }
        int uglyNum = uglys[n - 1];
        delete[] uglys;
        return uglyNum;
    }
};

