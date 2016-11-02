/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j, lenh = haystack.length(), lenn = needle.length();
        if (lenn == 0)  return 0;
        for (i = 0; i <= lenh - lenn; i++) {
            for (j = 0; j < lenn; j++) 
                if (haystack[i + j] != needle[j]) break;
            // 匹配成功
            if (j == lenn)  return i;
        }
        return -1;
    }
};
