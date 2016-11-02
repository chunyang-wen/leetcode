/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set &dict) {
        if (start == end) {
            return 1;
        }
        int n = start.size();
        if (n < 1 || n != end.size()) {
            return 0;
        }
 
        queue Q;
        Q.push(start);
        dict.erase(start);
        int length = 2;
 
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                string word = Q.front(); Q.pop();
                for (int i = 0; i < n; i++) {
                    char oldChar = word[i];
                    for (char c = "a"; c <= "z"; c++) {
                        if (c == oldChar) continue;
                        word[i] = c;
                        if (word == end) {
                            return length;
                        }
                        if (dict.find(word) != dict.end()) {
                            Q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = oldChar;
                }
            } // for size
            length++;
        }
        return 0;
    }
};

