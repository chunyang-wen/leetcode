/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /*
    题意为求最长回文子串， 直接枚举子串首尾位置再判断是否会问，时间复杂度为O(N^3)，
    换个思路，枚举回文串的对称中心位置，向两侧扫描检测最长回文长度时间复杂度为O(N^2)
    对于最长回文子串问题有对应O(N)算法--Manacher算法
    笔者觉得面试中应当不会有这么高的要求，有兴趣可以自行了解该算法
    */    
    string longestPalindrome(string s) {
        string str = "", ans = "";
        int len = s.length();
        int maxl = -1, cnt;
        for (int i = 0; i < len; i++) {
            str += "#";
            str += s[i];
        }
        str += "#";
        // 将原字符串扩展成#a#b#的形式可以直接枚举长度，不用考虑回文串长度的奇偶性
        for (int i = 1; i < 2 * len; i++) {
            cnt = 0;
            while ((i - cnt >= 0) && (i + cnt <= 2 * len) && (str[i - cnt] == str[i + cnt]))
                cnt++;
            cnt--;
            if (cnt > maxl) {
                maxl = cnt;
                ans = s.substr((i - cnt) / 2, (i + cnt) / 2 - (i - cnt) / 2);
            }
        }
        return ans;
    }
};
