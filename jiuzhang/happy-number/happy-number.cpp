/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        unordered_set showedNums;
        showedNums.insert(n);

        while (true) {
            int s = 0;
            while (n) {
                s += (n % 10) * (n % 10);
                n = n / 10;
            }

            if (s == 1)
                return true;
            else if (showedNums.find(s) != showedNums.end())
                return false;
            n = s;
            showedNums.insert(s);
        }
    }
};
