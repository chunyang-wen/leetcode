/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /*
    题意: 将罗马数字转换成int
    按照转换表模拟即可
    */
    int romanToInt(string s) {
        map num;
        num["I"] = 1;
        num["V"] = 5;
        num["X"] = 10;
        num["L"] = 50;
        num["C"] = 100;
        num["D"] = 500;
        num["M"] = 1000;
        int ans = num[s[s.length() - 1]];
        for (int i = s.length() - 2; i >= 0; i--) {
            if (num[s[i]] < num[s[i + 1]])
                ans -= num[s[i]];
            else
                ans += num[s[i]];
        }
        return ans;
    }
};
