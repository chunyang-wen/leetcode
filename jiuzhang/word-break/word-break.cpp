/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    int getMaxLength(unordered_set &dict) {
        int maxLength = 0; // 试试看中文 
        for (unordered_set::iterator it = dict.begin(); it != dict.end(); ++it) { 
            maxLength = maxLength > (*it).length() ? maxLength : (*it).length();
        }
        return maxLength;
    }
    
    bool wordBreak(string s, unordered_set &dict) {
        int maxLength = getMaxLength(dict);
        bool *canSegment = new bool[s.length() + 1];
        canSegment[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            canSegment[i] = false;
            for (int j = 1; j <= maxLength && j <= i; j++) {
                if (!canSegment[i - j]) {
                    continue;
                }
                string word = s.substr(i - j, j);
                if (dict.find(word) != dict.end()) {
                    canSegment[i] = true;
                    break;
                }
            }
        }
        
        return canSegment[s.length()];
    }
};

