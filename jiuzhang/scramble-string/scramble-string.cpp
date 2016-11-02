/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s1 == s2)
            return true;
        
        int size = s1.size();
        
        int value1=0, value2=0;
        for (int i=0; i<size; ++i) {
            value1 += (s1[i]-"a");
            value2 += (s2[i]-"a");
        }
        if (value1 != value2)
            return false; 
        
        for (int i=1; i<size;i++) {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.
substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0,i), s2.substr(size-i)) && isScramble(
s1.substr(i), s2.substr(0,size-i)))
                return true;
        }

        return false;
    }
};


class Solution {
public:
    bool sameCharset(string &s1, string &s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        
        unordered_map count;
        for (int i = 0; i < s1.length(); i++) {
            if (count.find(s1[i]) == count.end()) {
                count[s1[i]] = 1;
            } else {
                count[s1[i]]++;
            }
        }
        for (int i = 0; i < s2.length(); i++) {
            if (count.find(s2[i]) == count.end()) {
                return false;
            } else {
                count[s2[i]]--;
                if (count[s2[i]] < 0) {
                    return false;
                }
            }
        }
        return true;
    }   
}
    
bool memoSearch(unordered_map &hash,
                    string s1, string s2) {
        string key = s1 + " " + s2;
        if (s1 == s2) {
            hash[key] = true;
            return true;
        }
        if (hash.find(key) != hash.end()) {
            return hash[key];
        }
        
        if (!sameCharset(s1, s2)) {
            hash[key] = false;
            return false;
        }
        
        int size = s1.length();
        for (int i = 1; i < size; i++) {
            if (memoSearch(hash, s1.substr(0, i), s2.substr(0, i)) && 
                    memoSearch(hash, s1.substr(i, size - i), s2.substr(i, size - i))) {
                hash[key] = true;
                return true;
            }
            if (memoSearch(hash, s1.substr(0, i), s2.substr(size - i, i)) &&
                    memoSearch(hash, s1.substr(i, size - i), s2.substr(0, size - i))) {
                hash[key] = true;
                return true;
            }
        }
        
        hash[key] = false;
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        unordered_map hash;
        return memoSearch(hash, s1, s2);
    }
};
