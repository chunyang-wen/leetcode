/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    string getSortedString(string &str) {
        static int count[26];
        for (int i = 0; i < 26; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < str.length(); i++) {
            count[str[i] - "a"]++;
        }
        
        string sorted_str = "";
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i]; j++) {
                sorted_str = sorted_str + (char)("a" + i);
            }
        }
        return sorted_str;
    }
    
    vector anagrams(vector<string> &strs) {
        unordered_map hash;
        
        for (int i = 0; i < strs.size(); i++) {
            string str = getSortedString(strs[i]);
            if (hash.find(str) == hash.end()) {
                hash[str] = 1;
            } else {
                hash[str] = hash[str] + 1;
            }
        }
        
        vector result;
        for (int i = 0; i < strs.size(); i++) {
            string str = getSortedString(strs[i]);
            if (hash.find(str) == hash.end()) {
                continue;
            } else {
                if (hash[str] > 1) {
                    result.push_back(strs[i]);
                }
            }
        }
        return result;
    }
};

