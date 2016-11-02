/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int longestPalindrome(string s) {
        int charStatArray[52];
        int oneTimeOddCount = 0;
        int evenCount = 0;
    
        // zero clearing of the array
        memset(charStatArray, 0, sizeof(charStatArray));
    
        // keep the times of appearance of each character in the array
        for (char ch: s) {
            if (ch >= 97) {
                charStatArray[26 + ch - "a"]++;
            }
            else {
                charStatArray[ch - "A"]++;
            }
        }
    
        // the answer is the count of characters that has even number of appereances.
        // for characters that has odd number of appereances,
        // their appereances minus 1 will make their apperances even.
        // And finally we can put an unused character in the middle of the palindrome
        // (if there is any).
        for (int cnt: charStatArray) {
            if (cnt != 0) {
                if (cnt % 2 == 0) {
                    evenCount += cnt;
                } else {
                    if (cnt == 1) {
                        oneTimeOddCount++;
                    }
                    else {
                        evenCount += cnt - 1;
                        oneTimeOddCount++;
                    }
                }
            }
        }
    
        return oneTimeOddCount > 0 ? 1 + evenCount : evenCount;
    }
};
