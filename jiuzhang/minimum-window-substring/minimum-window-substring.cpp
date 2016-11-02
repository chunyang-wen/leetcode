/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map mp;
        for (char now : t) {
            mp[now] ++;
        }
        int count = mp.size();
        int j = 0;
        int ans = INT_MAX;
        string res; 
        for (int i = 0; i < s.size(); i++) {
            while(count != 0 && j < s.size()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
                j++;
                if (count == 0) {
                    break;
                }
            }
            if (count == 0 && j - i< ans) {
                ans = j - i;
                res = s.substr(i, j - i);
                
            }
            if(mp[s[i]] == 0) {
                count++;
            }
            mp[s[i]]++;
        }
        return res;
    }
};
