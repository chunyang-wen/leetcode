/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /*
    题意： 正则表达式匹配，"."可以匹配任意字符，"*"可以匹配任意个(可以为0)"*"之前的字符
    不考虑"*"的话，题目变成简单的匹配。考虑"*"，可能产生的情况有匹配0、1、2…个字符
    因此可以使用递归或dp或其他方法解决
    */
    bool isMatch(string s, string p) {
        if (s.length() == 0){
            // s串匹配完合法的情况只有p为空，或是 "X*X*"的形式
            if (p.length() & 1) return false;
            else {
                for (int i = 1; i < p.length(); i += 2) {
                    if (p[i] != "*") return false;
                }
            }
            return true;
        }
        if (p.length() == 0) return false;
        if (p.length() > 1 && p[1] == "*") {
            if (p[0] == "." || s[0] == p[0]) {
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            } else return isMatch(s, p.substr(2));
        } else {
            if (p[0] == "." || s[0] == p[0]) {
                return isMatch(s.substr(1), p.substr(1));
            } else return false;
        }
    }
};
