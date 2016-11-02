/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 题意为求不包含重复字符的最长子串
        // left用以记录合法的最远左边界位置，last记录字符上一次出现的位置
        int ans = 0, left = 0, len = s.length();
        int last[255];
        memset(last, -1, sizeof last);
        
        for (int i = 0; i < len; i++) {
            // 上次出现位置在当前记录边界之后，即该子串中出现了重复字符，需调整left使得子串合法
            if (last[s[i]] >= left) left = last[s[i]] + 1;
            last[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
