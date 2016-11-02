/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// This solution cost only O(n * m) time where n is length of the master string s. m is the length of each word.
// This solution"s algorithm is using sliding window to optimize the traverse of the string.
// directly for every start index and then determine whether this start index is a legal result will cost O(n * m * k) time where k is the numbers of words.

class Solution {
public:
    vector findSubstring(string s, vector<string>& words) {
        vector result;
        if (words.size() == 0) {
            return result;
        }
        
        unordered_map hash;
        for (int i = 0; i < words.size(); i++) {
            if (hash.find(words[i]) == hash.end()) {
                hash[words[i]] = 1;
            } else {
                hash[words[i]]++;
            }
        }
        
        int wSize = words[0].length();
        for (int start = 0; start < wSize; start++) {
            int wCount = 0;
            unordered_map slidingWindow;
            for (int i = start; i + wSize <= s.length(); i+=wSize) {
                string word = s.substr(i, wSize);
                if (hash.find(word) == hash.end()) {
                    slidingWindow.clear();
                    wCount = 0;
                } else {
                    wCount++;
                    if (slidingWindow.find(word) == slidingWindow.end()) {
                        slidingWindow[word] = 1;
                    } else {
                        slidingWindow[word]++;
                    }
                    while (hash[word] < slidingWindow[word]) {
                        string removedWord = s.substr(i - (wCount-1) * wSize, wSize);
                        slidingWindow[removedWord]--;
                        wCount--;
                    }
                }
                
                if (wCount == words.size()) {
                    result.push_back(i - (wCount - 1) * wSize);
                }
            }
        }
        
        return result;
    }
};
